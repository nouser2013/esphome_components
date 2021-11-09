#include "esphome/core/log.h"
#include "mi_switch.h"

namespace esphome {
  namespace mi {

    static const char *const TAG = "mi.switch";

    void MiSwitch::setup() {}

    void MiSwitch::write_state(bool state) {

      this->turn_off();
      parent_->handleCommand(bulbId, command_);
      this->publish_state(state);
    }

    void MiSwitch::dump_config() {
      LOG_SWITCH("", "Mi Switch", this);
    }
    
    void MiSwitch::set_switch(uint16_t deviceId, uint8_t groupId, String remoteType, String command) {
      MiSwitch::bulbId = {
        deviceId, 
        groupId, 
        MiLightRemoteConfig::fromType(remoteType)->type
      };
      command_ = command;
    }

  }  // namespace mi
}  // namespace esphome
