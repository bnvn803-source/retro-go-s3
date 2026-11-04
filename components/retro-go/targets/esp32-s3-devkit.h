// Generic ESP32-S3 N16R8 DevKit + ST7789 320x240 + KY-023 + SPI MicroSD
// Pin map is for the user's custom wiring, not an official development board.

#define RG_TARGET_NAME             "ESP32-S3-DEVKIT"

// MicroSD over SPI (separate SPI host from the display)
#define RG_STORAGE_DRIVER           1
#define RG_STORAGE_HOST             SPI3_HOST
#define RG_STORAGE_SPEED            SDMMC_FREQ_DEFAULT
#define RG_STORAGE_ROOT             "/sd"

// Audio: external I2S DAC/amplifier (e.g. MAX98357A)
#define RG_AUDIO_USE_INT_DAC        0
#define RG_AUDIO_USE_EXT_DAC        1
#define RG_GPIO_SND_I2S_BCK         GPIO_NUM_41
#define RG_GPIO_SND_I2S_WS          GPIO_NUM_42
#define RG_GPIO_SND_I2S_DATA        GPIO_NUM_40

// ST7789 320x240, using the ST7789V2 init sequence already present in this fork
#define RG_SCREEN_DRIVER            0
#define RG_SCREEN_HOST              SPI2_HOST
#define RG_SCREEN_SPEED             SPI_MASTER_FREQ_40M
#define RG_SCREEN_TYPE              4
#define RG_SCREEN_WIDTH             320
#define RG_SCREEN_HEIGHT            240
#define RG_SCREEN_ROTATE            0
#define RG_SCREEN_MARGIN_TOP        0
#define RG_SCREEN_MARGIN_BOTTOM     0
#define RG_SCREEN_MARGIN_LEFT       0
#define RG_SCREEN_MARGIN_RIGHT      0

#define RG_GPIO_LCD_MISO            GPIO_NUM_NC
#define RG_GPIO_LCD_MOSI            GPIO_NUM_12
#define RG_GPIO_LCD_CLK             GPIO_NUM_48
#define RG_GPIO_LCD_CS              GPIO_NUM_NC
#define RG_GPIO_LCD_DC              GPIO_NUM_47
#define RG_GPIO_LCD_BCKL            GPIO_NUM_39
#define RG_GPIO_LCD_RST             GPIO_NUM_3

// KY-023: VRX=GPIO7/ADC1_CH6, VRY=GPIO6/ADC1_CH5, SW=GPIO15.
// Buttons are active-low and should be wired to GND when pressed.
#define RG_GAMEPAD_DRIVER           1
#define RG_GAMEPAD_HAS_MENU_BTN     1
#define RG_GAMEPAD_HAS_OPTION_BTN   1
#define RG_GPIO_GAMEPAD_X           ADC1_CHANNEL_6
#define RG_GPIO_GAMEPAD_Y           ADC1_CHANNEL_5
#define RG_GPIO_GAMEPAD_SELECT      GPIO_NUM_16
#define RG_GPIO_GAMEPAD_START       GPIO_NUM_17
#define RG_GPIO_GAMEPAD_A           GPIO_NUM_15
#define RG_GPIO_GAMEPAD_B           GPIO_NUM_5
#define RG_GPIO_GAMEPAD_MENU        GPIO_NUM_18
#define RG_GPIO_GAMEPAD_OPTION      GPIO_NUM_8

// SPI MicroSD 6-pin module: CS, SCK, MOSI, MISO, VCC, GND
#define RG_GPIO_SDSPI_MISO          GPIO_NUM_9
#define RG_GPIO_SDSPI_MOSI          GPIO_NUM_11
#define RG_GPIO_SDSPI_CLK           GPIO_NUM_13
#define RG_GPIO_SDSPI_CS            GPIO_NUM_10

// No battery monitor / status LED configured.
