#include "esphome.h"
#include "Adafruit_VCNL4040.h"

class VCNL4040Sensor : public PollingComponent, public Sensor {
 public:
  Adafruit_VCNL4040 vcnl4040 = Adafruit_VCNL4040();

  Sensor *lux_sensor = new Sensor();
  Sensor *proximity_sensor = new Sensor();
  Sensor *whitelight_sensor = new Sensor();

  // constructor
  VCNL4040Sensor() : PollingComponent(15000) {}

 
  void setup() override {
    // This will be called by App.setup()
    Wire.begin();
    vcnl4040.begin();
  }
  void update() override {
    // This will be called every "update_interval" milliseconds.
    lux_sensor->publish_state(vcnl4040.getLux());
    proximity_sensor->publish_state(vcnl4040.getProximity());
    whitelight_sensor->publish_state(vcnl4040.getWhiteLight());
  }
};

