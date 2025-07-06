
///@file
// @brief struct Light
///

// This bitmask masks the dip_switch at Port A
const uint8_t kBitmaskAddress = 0x3F;

// This bit says if it is an control device or a gear device
const uint8_t kBitmaskControl = 0x80;

// This bit says if it is Dali or DMX
const uint8_t kBitmaskDali = 0x40;

// This bitmask masks three Bits
const uint8_t kBitmaskAddressDMX = 0x0C;

struct Dali {
  uint8_t address;
  uint8_t pointer;
  uint16_t intensity;
};

struct Dmx {
  uint8_t intensity;
  uint16_t address;
};

struct Light { 
  uint8_t dip_switch;
  uint8_t pointer;

  Uint16_t address;
  uint16_t intensity;

  struct Output output;
};

void InitDali(*struct Dali) {
  address = PortA();
  pointer = 0;
  intensity = 1;
}

void InitDmx(*struct Dmx) {
  address = PortA() + PortB();
  intensity = 1;
}

