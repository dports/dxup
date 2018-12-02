#include "dx9asm_translator.h"
#include "dx9asm_operations.h"
#include "../util/config.h"
#include "../util/misc_helpers.h"

namespace dxapex {

  namespace dx9asm {

    bool ShaderCodeTranslator::handleOperation(uint32_t token) {
      DX9Operation operation{ *this, token };
      if (!operation.isValid()) {
        log::fail("Unknown operation encountered!");
        return false;
      }

      if (config::getBool(config::ShaderSpew))
        log::msg("Translating operation %s.", operation.getName());

      if (operation.isUnique())
        return handleUniqueOperation(operation);
      else
        return handleStandardOperation(operation);

      return true;
    }

    bool ShaderCodeTranslator::translate() {
      nextToken(); // Skip header.

      uint32_t token = nextToken();
      while (token != D3DPS_END()) {
        if (!handleOperation(token))
          return false;
        token = nextToken();
      }

      DXBCOperation{ D3D10_SB_OPCODE_RET, false }.push(*this);

      return true;
    }
  
    void toDXBC(const uint32_t* dx9asm, ITranslatedShaderDXBC** dxbc) {
      InitReturnPtr(dxbc);

      ShaderCodeTranslator translator{dx9asm};
      if (!translator.translate()) {
        log::fail("Failed to translate shader fatally!");
        return;
      }

      
    }

  }

}