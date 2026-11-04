# ESP32-S3 N16R8 custom target setup

This patch adds a custom `esp32-s3-devkit` target for the following wiring. It is not a ready-made binary: build it with the GitHub Actions workflow `Retro-Go ESP32-S3 Cloud Build`.

## Pin map

| Function | ESP32-S3 GPIO |
|---|---:|
| ST7789 MOSI / SCLK / DC / BL / RST | 12 / 48 / 47 / 39 / 3 |
| ST7789 CS | NC (tie the module CS low if the board requires it) |
| MicroSD MISO / MOSI / SCK / CS | 9 / 11 / 13 / 10 |
| KY-023 VRX / VRY / SW | 7 / 6 / 15 |
| A / B / SELECT / START / MENU / OPTION | 15 / 5 / 16 / 17 / 18 / 8 |
| I2S BCLK / LRC(WS) / DIN | 41 / 42 / 40 |

KY-023 and button inputs use 3.3V logic. Connect button contacts between GPIO and GND. GPIO15 is shared by KY-023 SW and A in this simple map; SW therefore acts as A. A separate B button is on GPIO5. Do not connect a passive speaker directly to an ESP32 GPIO: use an I2S amplifier such as MAX98357A.

## Cloud build

1. Upload this project to a GitHub repository.
2. Open **Actions** and run **Retro-Go ESP32-S3 Cloud Build**.
3. Download the `Retro-Go-ESP32-S3` artifact. It should contain one `.img` file.
4. Flash that single image at address `0x000000` with an ESP32 flasher.

The S3 defaults are configured for 16MB flash in DIO/40MHz mode and octal PSRAM. Confirm the actual PSRAM type on the board before treating the build as hardware-validated. The workflow has not been run against the user's physical board; first boot and pin directions still require testing.

## Notes

- The KY-023 analog mapping includes a neutral dead zone (raw ADC 1000–3000). If directions are reversed, swap the UP/DOWN or LEFT/RIGHT comparisons in `components/retro-go/rg_input.c`.
- The MicroSD module should be powered at 3.3V unless its breakout explicitly includes a regulator and level shifters.
- ROMs and BIOS files follow the paths documented in `README.md`.
