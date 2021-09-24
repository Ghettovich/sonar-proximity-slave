#include <SPI.h>
#include <mcp_can.h>

const int SPI_CS_PIN = 53;
const int id = 0x01;
unsigned char messageId = 1;
unsigned short value = 255;

MCP_CAN CAN(SPI_CS_PIN);

canMsgBuffer* canBuffer;
const int CAN_MSG_SIZE = 3;

void setupCAN() {
  while (CAN_OK != CAN.begin(CAN_500KBPS)) {            // init can bus : baudrate = 500k
    Serial.println("CAN BUS Shield init fail");
    Serial.println("Init CAN BUS Shield again");
    delay(100);
  }
  Serial.println("CAN BUS Shield init ok!");

  // init can buffer message
  canBuffer = canBufferInit(CAN_MSG_SIZE);
}

void canLoop() {
  Serial.println("in loop");
  
  value++;
  prepareBuffer(messageId, value, canBuffer);

  // check if size does not exceed the reserved length
  if (sizeof(canBuffer->data) <= MAX_CHAR_IN_MESSAGE) {
    CAN.sendMsgBuf(id, 0, canBuffer->size, canBuffer->data);
  }

  delay(1000);
}
