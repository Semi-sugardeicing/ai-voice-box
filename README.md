# AI Voice Box · AI 盒子

**ESP32-S3-N16R8** · DeepSeek voice assistant with Chinese OLED UI, 4-key control, and OTA updates.

**ESP32-S3-N16R8** · 基于 DeepSeek 的语音助手，中文 OLED 界面 + 四键操作 + 无线升级。

---

## Features / 功能

| English | 中文 |
|---|---|
| Hold-to-talk voice assistant (ASR → Chat → TTS) | 按住说话，识别→对话→合成一条龙 |
| Chinese UI rendered from hand-built 16×16 dot matrix | 中文界面，16×16 点阵自行生成 |
| Balance + daily spend + context usage on idle screen | 首页显示余额、今日花费、上下文占用 |
| Peak-hour LED indicator (red = peak, green = off-peak) | 峰谷灯：高峰期红灯，低谷绿灯 |
| Auto night mode 22:00–07:00 (dims screen, LED off) | 夜间模式 22:00–07:00，自动暗屏关灯 |
| 4-key menu: brightness / volume / LED / extras | 四键菜单：亮度、音量、走马灯、更多 |
| API key stored on device (web config), never in firmware | 密钥存盒子内(网页配置)，固件不含密钥 |
| Manual update check: from PC (LAN) or GitHub | 菜单手动检查更新：电脑/GitHub 双源 |
| OTA update over WiFi (password protected) | WiFi 无线升级，带口令保护 |
| Auto firmware check on boot | 开机自动检查新固件 |

---

## Hardware / 硬件清单

| Part | 型号 | Notes / 说明 |
|---|---|---|
| MCU | ESP32-S3-N16R8 | 16MB Flash / 8MB PSRAM |
| Display | SSD1306 0.96" | I2C, addr 0x3C |
| Microphone | INMP441 | I2S, 16 kHz mono |
| Amplifier | MAX98357A | I2S, SD pin to 3.3V |
| Keys | 4-key module | optional / 可选 |

---

## Wiring / 接线

```
MIC  INMP441 : VDD→3.3V  GND→GND  L/R→GND  WS→10  SCK→11  SD→12
SPK  MAX98357: VIN→5V    GND→GND  SD→3.3V  DIN→4  BCLK→5  LRC→6
OLED SSD1306 : SDA→8     SCL→9    VCC→3.3V GND→GND
KEYS 4-key   : COM→GND   ∧→13   ∨→14   #→15   ⌘→16
```

> ⚠️ MAX98357 `SD` pin **must** go to 3.3V. Pulling it to GND mutes the amp.
> ⚠️ MAX98357 的 `SD` 脚**必须**接 3.3V，接 GND 会静音。

---

## Quick Start / 快速开始

**1. Fill in your credentials / 填入凭据**

```cpp
const char* DEEPSEEK_KEY = "sk-你的密钥";

WiFiItem WIFI_LIST[] = {
  { "你的WiFi名字", "你的WiFi密码" },
};
```

**2. Install libraries / 安装库**

`Adafruit SSD1306` · `Adafruit GFX` · `Adafruit NeoPixel` · `ArduinoJson`

**3. Board settings / 开发板设置**

| Setting | Value |
|---|---|
| Board | ESP32S3 Dev Module |
| Flash Size | 16MB |
| PSRAM | OPI PSRAM |
| Partition Scheme | **8M with spiffs (3MB APP)** — required for OTA |

> OTA needs the `default_8MB` partition table. First flash must be done over USB.
> OTA 需要 `default_8MB` 分区表，首次烧录必须走 USB。

**4. Flash & talk / 烧录说话**

Hold `⌘` to speak, release to get an answer.
按住 `⌘` 说话，松开自动回答。

---

## Key Map / 按键说明

| Key | Symbol | GPIO | Function |
|---|---|---|---|
| K1 | ∧ | 13 | spare / 预留 |
| K2 | ∨ | 14 | brightness / 亮度 |
| K3 | # | 15 | menu · replay / 菜单 · 重播 |
| K4 | ⌘ | 16 | hold to talk / 按住说话 |

---

## OTA Update / 无线升级

```bash
curl -F "firmware=@AIBox.ino.bin" http://aibox:PASSWORD@<DEVICE_IP>:8080/update
```

Set `OTA_PASS` in the sketch to your own password.
把代码里的 `OTA_PASS` 改成你自己的口令。

For automatic updates, serve `version.txt` + `AIBox.ino.bin` from a local HTTP server and point `UPDATE_HOST` at it.
自动更新：用本地 HTTP 服务提供 `version.txt` 和固件，把 `UPDATE_HOST` 指向它。

---

## Troubleshooting / 常见问题

| Symptom / 现象 | Cause / 原因 |
|---|---|
| Crackling audio / 炸麦 | Overdriven output; lower `SPK_GAIN` / 输出过载，降低 `SPK_GAIN` |
| Silent speaker / 喇叭无声 | `SD` pin not at 3.3V, or TTS buffer parse failure / `SD` 未接 3.3V，或语音数据解析失败 |
| Only first ~11s plays / 只播前 11 秒 | TTS buffer is 512KB ≈ 11s; enlarge `cap` / 缓冲 512KB 约 11 秒，加大 cap |
| 中文乱码 | Font missing / 字库缺失；本项目内置 16×16 点阵 |

---

## License / 许可证

MIT
