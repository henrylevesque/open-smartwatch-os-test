#pragma once

#include <OswAppV2.h>
#include "../../lib/doom_shim/doom_shim.h"

class OswAppDoom: public OswAppV2 {
  public:
    OswAppDoom();
    virtual const char* getAppId() override;
    virtual const char* getAppName() override;
    virtual void onStart() override;
    virtual void onLoop() override;
    virtual void onDraw() override;
    virtual void onButton(Button id, bool up, ButtonStateNames state) override;
  private:
    unsigned long lastTick = 0;
    int frame = 0;
  bool engineRunning = false;
  std::string wadPath;
};
