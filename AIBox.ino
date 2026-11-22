/*
  ========================================
   版本: v54 (菜单反色高亮 + K3 专门做确定)
   日期: 2026-11-22
   改动一: 菜单改成"焦点在选项上": 被选中的项显示成白底黑字(反色)。
   改动二: 按键分工定稿 —— 菜单外 K1/K2 无反应; 菜单里 K1/K2 移动光标,
           K3 短按=确定(保存生效), 长按 K3=退出菜单。
   改动三: 屏幕亮度 / 喇叭音量(5档) / 走马灯(4档) 只能在菜单里改, 断电记忆。
   上一版: v53 (按键自检屏 + 菜单外 K1/K2 也有反应)
   日期: 2026-11-22
   改动一: 同时按住 K1+K2 一秒 -> 按键自检屏, 直接显示四个键当前电平和引脚号,
           用来排查"按键没反应"到底是哪根线/哪个脚的问题。按住 K4 两秒退出。
   改动二: 菜单外 K1=暗一档 / K2=亮一档, 立刻有反应(以前只有 K3/K4 有用)。
   上一版: v52 (OTA推送也有底部进度条 + 设密钥立刻显示余额)
   日期: 2026-11-22
   改动一: 电脑 curl 推送固件时, 屏幕除了 KB 数再加底部进度条+百分比
           (总大小取 HTTP 请求 Content-Length 估算)。
   改动二: 网页 /config 保存密钥后立刻刷新余额上屏, 不用再等 10 分钟。
   上一版: v51 (版本号常驻首页右下角)
   日期: 2026-11-22
   改动: 首页右下角永远显示 v+版本号(以前没密钥时被 NO KEY 占用),
        没密钥时改为大字下方两行提醒: NO KEY + 配置页地址。
   上一版: v50 (密钥进盒子存储 + K3菜单 + 音量/走马灯进菜单)
   日期: 2026-11-22
   改动一: DeepSeek 密钥不再写在固件里! 改成存在盒子自己的存储(NVS)里,
           浏览器开 http://盒子IP:8080/config 输入一次, 以后刷任何版本固件
           密钥都在 —— 这是防泄露的关键: 固件文件(包括发到 GitHub 的)里
           不再含任何密钥。
   改动二: 按键重排: K1∧/K2∨ = 菜单里上下选择/调值, K3# = 菜单键
           (进入/确认, 长按退出), K4米字 = 按住说话(不变)。
   改动三: K3 菜单项: 屏幕亮度 / 喇叭音量(5档) / 走马灯(自动/红/绿/关)
           / 重播 / 检查更新(从电脑 / 从 GitHub)。
   改动四: 亮度/音量/走马灯三档设置断电不丢(存NVS)。
   上一版: v49 (首页右下角显示版本号)
   日期: 2026-11-21
   改动: 首页底部右下角加小字版本号, 一眼看出板子跑哪一版
   上一版: v48 (版本查询接口 + 电脑/GitHub 双源更新)
   日期: 2026-11-21
   改动一: 新增 GET /version 接口, 电脑上 curl 一下就能看板子跑的是哪一版
   改动二: 更新改为双源 —— 先问家里的电脑, 电脑不通再问 GitHub
   改动三: 更新界面显示来源(FROM PC / FROM GITHUB)
   上一版: v47 (开机检查 + 5秒倒计时 + K4取消 + 进度条)
   日期: 2026-11-21
   改动一: 开机自动查 GitHub, 发现新版本时屏幕显示版本号并倒数 5 秒
   改动二: 倒计时内按 K4 可取消本次更新, 板子保持当前版本
   改动三: 下载时屏幕显示进度条 + 已下载KB + 百分比
   上一版: v46 (直连 GitHub 自动更新)
   日期: 2026-11-21
   改动一: 首页那个大字时间去掉, 改成左上角小字 "时:分 上下文/4K"(无秒)
   改动二: 夜间时段改为 22:00-07:00 (她要睡觉), 走马灯灭 + 屏幕自动变暗
   改动三: 底部加 CTX 占用 + 今日对话轮数 T，方便看上下文用了多少
   上一版: v43 (修死循环: 不说话不再卡死)
   日期: 2026-11-21
   修复一: 按 K4 不说话/识别失败时, 原来会进入"翻页显示服务器原始响应"的
           死循环(满屏好几行, 整台机器卡死只能断电)。改为提示 3 秒回待机。
   修复二: WiFi 连不上原来 while(1) 死等, 改为每 5 秒自动重试。
   上一版: v42 (首页改版: 余额+今日花费+时分 / 语音键改 K4 / 夜间模式)
   日期: 2026-11-21
   改动一: 首页去掉 BALANCE 字样, 大字余额 + CNY + TODAY 花费 + 时分(无秒)
   改动二: 按住说话键改到 K4(GPIO16); K2 亮度 / K3 重播 / K1 预留
   改动三: 余额每 10 分钟自动查一次
   改动四: 夜间(23:00-07:00) 关走马灯 + 屏幕自动变暗, 白天恢复
   上一版: v40 (接电源就能自动更新)
   日期: 2026-11-21
   改动: 开机连上 WiFi 后自动查电脑上的 version.txt, 比本机 FW_VER 大就下载
         aibox.ino.bin 升级并重启 — 板子只要接电 + 同 WiFi, 不用插电脑。
         电脑端: %USERPROFILE%\aibox-fw 目录 + python http.server 8000(开机自启)
   上一版: v39 (OTA 无线升级)
   日期: 2026-11-21
   改动: 加 OTA 服务 — 板子开机后可通过网络推送新固件, 不用插 USB:
         电脑执行 curl -X POST --data-binary "@aibox.ino.bin" http://<板子IP>:8080/update
         屏幕上显示进度百分比, 传完自动重启。
         ⚠️ 分区表必须换成 default_8MB (双 3.3MB 应用区, 带 OTA),
            首次烧录仍需 USB。
  ========================================
   上一版: v38 (单键保险版: 任意键 = 按住说话)
  ========================================

  AI 盒子 v1 完整版
  说话 -> DeepSeek ASR 识别 -> DeepSeek 对话 -> DeepSeek TTS -> 喇叭播放

  【要改的地方】(v50 起不再需要填密钥!)
    1. WiFi 在 WIFI_LIST 里, 已经填好家里和热点两个, 不够自己加行
    2. DeepSeek 密钥: 不用写代码! 板子开机后浏览器打开
       http://板子IP:8080/config  (口令 aibox / 见 OTA_PASS) 填一次,
       密钥存在盒子自己的存储里, 以后刷任何固件都不会丢。

  【接线】
    麦克风 INMP441: VDD->3.3V  GND->GND  L/R->GND  WS->10  SCK->11  SD->12
    喇叭 MAX98357: VIN->5V  GND->GND  SD->3.3V  DIN->4  BCLK->5  LRC->6
    屏幕 SSD1306:  SDA->8  SCL->9  VCC->3.3V  GND->GND
    按键: 不用

  【用法】
    开机 -> 校准 2 秒(保持安静) -> 说话
    说完静 1.5 秒自动停止 -> 识别 -> 对话 -> 播放
    屏幕实时显示 能量条 / STOP 倒计时 / TOK 和 CNY 费用
*/

/* 固件版本号 —— 必须在最前面, 首页/版本接口/更新逻辑都要用 */
#define FW_VER       55

#include <WiFi.h>
#include <WiFiMulti.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <time.h>
#include <driver/i2s.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>
#include <WebServer.h>   /* v39: OTA */
#include <Update.h>      /* v39: OTA */
#include <Preferences.h> /* v50: 密钥/设置存盒子存储(NVS), 刷固件不丢 */
#include <DNSServer.h>   /* v55: 配网热点 (连不上任何 WiFi 时自己开热点) */

/* ##################################################################
   ######################  只改这两处  ##############################
   ################################################################## */

/* ========== 1. DeepSeek 密钥 (v50 起): 不用写在这里! ==========
   密钥存在盒子自己的存储(NVS)里, 浏览器打开 http://盒子IP:8080/config
   输入一次即可, 以后刷任何版本固件密钥都在, 固件文件里永不含密钥。 */
String g_key = "";   /* 运行时从 NVS 读入, 见 loadSettings() */

/* ========== 2. WiFi 列表: 有几组写几组, 复制一行改名字密码即可 ==========
   格式:  { "WiFi名字", "WiFi密码" },
   可以写任意多个, 自动连能连上的那个。                       */
struct WiFiItem { const char* ssid; const char* pass; };
/* v55: 这里留空也能用 —— 开机连不上就自己开热点 AIBox-Setup,
   手机连上去填 WiFi 名和密码, 存在盒子里。想预置可以照下面格式加。 */
WiFiItem WIFI_LIST[] = {
  { "预置WiFi名", "预置密码" },
  /* { "新的WiFi名", "新的密码" }, */
};

/* ##################################################################
   ######################  下面不用改  ##############################
   ################################################################## */

/* ================== 接口地址 ================== */
const char* ASR_URL   = "https://api.deepseek.com/v1/tools/asr";
const char* CHAT_URL  = "https://api.deepseek.com/chat/completions";
const char* TTS_URL   = "https://api.deepseek.com/v1/tools/tts";
const char* MODEL_CHAT = "deepseek-flash";
const char* TTS_VOICE  = "stella";

/* ================== 引脚 ================== */
#define RGB_PIN       48
#define I2S_MIC_PORT  I2S_NUM_1
#define I2S_MIC_SCK   11
#define I2S_MIC_WS    10
#define I2S_MIC_SD    12
/* ================== 按键 (v35: 4 键屏模块) ==================
   接线: 屏的 GND/VCC 照旧, SDA=8 SCL=9 照旧;
        4 个键的公共端接 GND, 信号线接下面 4 个针脚(内部上拉, 按下=低电平)。
   功能: K1 按住说话 / K2 查余额 / K3 静音开关 / K4 重播上一句
   AUTO_LISTEN=1 恢复旧的自动监听(不用按键, 有环境音误触发问题)。*/
/* v42 按键 (按键模块上印的符号 -> 针脚):
     K1  印"∧" (上箭头)  -> GPIO13  预留
     K2  印"∨" (下箭头)  -> GPIO14  屏幕亮度: 最亮 -> 次亮 -> 熄屏 -> 循环
     K3  印"#"           -> GPIO15  重播上一句
     K4  印"⌘/米字"      -> GPIO16  按住说话
   注意: ∧ 和 ∨ 是上下箭头, 不是字母 A / V。 */
#define BTN_K1       13   /* 印 ∧ */
#define BTN_BRIGHT   14   /* 印 ∨  亮度三档 */
#define BTN_REPLAY   15   /* 印 #  重播 */
#define BTN_TALK     16   /* 印 米字  按住说话 */

/* 单键模式: 只插了一个键、不确定插的哪个孔时开这个 ——
   13/14/15/16 任意一个按下都当"按住说话"。
   以后四个键都接好、要恢复分工, 把它改成 0。 */
#define SINGLE_KEY   0
#define AUTO_LISTEN  0

/* 屏幕亮度: 2=最亮 1=次亮 0=熄屏 */
int g_bright = 2;
/* v42 定时: 余额每 10 分钟查一次, 夜间模式每分钟同步 */
unsigned long lastBalMs = 0, lastNightMs = 0;

/* ================== v50: 盒子存储 (NVS) ==================
   密钥 + 亮度 + 音量 + 走马灯 都存这里, 刷固件(OTA/GitHub)不丢,
   固件文件里永不含密钥 —— 防泄露的关键设计。 */
Preferences prefs;

/* v50 菜单设置项 */
int g_volIdx = 1;      /* 音量档 0..4 = 20%..100%, 默认 40% */
int g_ledMode = 0;     /* 走马灯: 0=自动(峰谷) 1=强制红 2=强制绿 3=关 */
float g_gain = 0.5f;   /* 播放数字增益 = 0.2*(g_volIdx+1), setup 时按 NVS 重算 */

/* v50 菜单状态: 0=关 1=浏览 2=调值 3=更新源选择 */
int menuActive = 0;
int menuCursor = 0;
int menuSub = 0;
unsigned long menuLastMs = 0;

/* ================== v55: WiFi 存在 NVS 里 ==================
   配网时手机填的 WiFi 名/密码存这里, 优先级高于固件里的 WIFI_LIST。
   这样以后换热点、换地方, 不用改代码、不用发新版本。 */
String g_wifiSsid = "";
String g_wifiPass = "";

void loadWifiCred() {
  prefs.begin("aibox", true);
  g_wifiSsid = prefs.getString("ssid", "");
  g_wifiPass = prefs.getString("pass", "");
  prefs.end();
  Serial.printf(">>> wifi in NVS: %s\n", g_wifiSsid.length() ? g_wifiSsid.c_str() : "(none)");
}

void saveWifiCred(const String& ssid, const String& pass) {
  prefs.begin("aibox", false);
  prefs.putString("ssid", ssid);
  prefs.putString("pass", pass);
  prefs.end();
  g_wifiSsid = ssid;
  g_wifiPass = pass;
  Serial.printf(">>> wifi saved to NVS: %s\n", ssid.c_str());
}

void loadSettings() {
  prefs.begin("aibox", true);
  g_bright  = prefs.getInt("bright", 2);
  g_volIdx  = prefs.getInt("vol", 1);
  g_ledMode = prefs.getInt("led", 0);
  g_key     = prefs.getString("key", "");
  prefs.end();
  if (g_bright < 0 || g_bright > 2) g_bright = 2;
  if (g_volIdx < 0 || g_volIdx > 4) g_volIdx = 1;
  if (g_ledMode < 0 || g_ledMode > 3) g_ledMode = 0;
  g_gain = 0.2f * (g_volIdx + 1);
  Serial.printf(">>> settings: bright=%d vol=%d%% led=%d key=%s\n",
                g_bright, (g_volIdx + 1) * 20, g_ledMode,
                g_key.length() >= 20 ? "SET" : "EMPTY");
}

void saveSettings() {
  prefs.begin("aibox", false);
  prefs.putInt("bright", g_bright);
  prefs.putInt("vol", g_volIdx);
  prefs.putInt("led", g_ledMode);
  prefs.end();
  Serial.println(">>> settings saved (NVS)");
}

/* 重播用的上一句音频 */
uint8_t* g_lastAudio = NULL;
long g_lastLen = 0, g_lastOff = 44, g_lastSamples = 0;
int  g_lastRate = 24000;
bool g_muted = false;
#define I2S_SPK_PORT  I2S_NUM_0
#define I2S_SPK_BCLK  5
#define I2S_SPK_LRC   6
#define I2S_SPK_DIN   4

/* ================== 录音参数 ================== */
const int sampleRate = 16000;
#define MAX_SAMPLES  80000          /* 5 秒 (16kHz x 5) */
#define BLOCK_MS    20

#define START_RATIO     4.0f
#define START_ABS       600
#define START_BLOCKS    3
#define STOP_RATIO      2.0f
#define STOP_BLOCKS    100          /* 2 秒静音就认定说完 */
#define MIN_SAMPLES     6400
#define CALIB_MS        2000

/* ================== 全局 ================== */
WiFiMulti wifiMulti;
int16_t* pcmBuf = NULL;
long pcmLen = 0;

Adafruit_SSD1306 display(128, 64, &Wire, -1);
bool screenOK = false;
Adafruit_NeoPixel pixels(1, RGB_PIN, NEO_GRB + NEO_KHZ800);

/* 底噪与门槛(全局, 避免重复校准) */
int g_baseline = 300;
int g_threshold = 600;

/* 等待动画的状态 */
const char* g_waitSub = "waiting";
unsigned long g_waitLast = 0;

/* 计费 */
long lastPromptTok = 0, lastCompTok = 0;
long lastCacheHit = 0, lastCacheMiss = 0;
long ctxTokens = 0;                 /* 当前上下文占用 */
#define CTX_MAX 4096                /* 超过就砍记忆 */
float todayCost = 0;
float lastCost = 0;              /* 上一轮花费 */
String g_balance = "";           /* 当前余额字符串, 空=未知 */
long todayTurns = 0;
bool wifiReady = false;

/* 对话记忆: 只留最近 2 轮 + 一句摘要 */
String history[4];         /* user, assistant, user, assistant */
int historyCount = 0;

/* 返回 "23:45" (只要时分, 不要秒) —— 前置声明, 供顶栏使用 */
const char* getTimeHM();

/* ================== 显示 ================== */
/* 顶栏: 左上 CTX 已用/上限, 右上 WiFi 状态。每次画屏最后都要调用 */
void drawTopBar() {
  if (!screenOK) return;
  /* 先把顶部 8 像素清干净, 防止上一次的字叠在一起变乱码 */
  display.fillRect(0, 0, 128, 9, SSD1306_BLACK);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  /* v44: 左上角 = 时间(只有时分) + 上下文占用 */
  display.setCursor(0, 0);
  display.print(getTimeHM());
  display.print(" ");
  display.print(ctxTokens);
  display.print("/4K");

  /* 右上角: WiFi 两个字, 没连上就打横线 */
  char buf[8];
  strcpy(buf, wifiReady ? "WiFi" : "----");
  int w = strlen(buf) * 6;
  display.setCursor(128 - w - 1, 0);
  display.print(buf);
}

void screen2(const char* a, const char* b) {
  if (!screenOK) return;
  display.clearDisplay();
  drawTopBar();                       /* 先画顶栏, 再画正文, 避免擦掉正文 */
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 13);
  display.println(a);
  display.setCursor(0, 26);
  display.println(b);
  display.display();
}

/* 状态 + 两行信息 */
void screenStatus(const char* s1, const char* s2, const char* s3) {
  if (!screenOK) return;
  display.clearDisplay();
  drawTopBar();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 13); display.println(s1);
  display.setCursor(0, 26); display.println(s2);
  display.setCursor(0, 39); display.println(s3);
  display.display();
}

/* ============ v33 中文点阵字库 (16x16, 文泉驿正黑提取, 9 字 288 字节) ============
   模型正在回答中 / 思考中。位序: bit15=最左像素。
   字符串用 \x 十六进制写死, 与文件编码无关, 永不乱码。*/
static const uint16_t ZH_FONT[][16] = {
  { 0x0000, 0x1190, 0x11B0, 0x11BC, 0x31B0, 0x31B8, 0x3308, 0x3B18, 0x7318, 0x7060, 0xD3EC, 0x10E0, 0x10B0, 0x119C, 0x1604, 0x0000 }, /* 模 */
  { 0x0000, 0x3608, 0x3668, 0x1668, 0x3668, 0xFF68, 0x1668, 0x2648, 0x6618, 0x4110, 0x0100, 0x3FF8, 0x0300, 0x0100, 0xFFFC, 0x0000 }, /* 型 */
  { 0x0000, 0x0000, 0x7FFC, 0x0100, 0x0100, 0x0100, 0x1180, 0x11F8, 0x1180, 0x1100, 0x1100, 0x1100, 0x1100, 0xFFFC, 0x0000, 0x0000 }, /* 正 */
  { 0x0000, 0x0200, 0x0200, 0x0600, 0x7FFC, 0x0400, 0x0840, 0x1840, 0x3BF8, 0x78E0, 0x4840, 0x0840, 0x0840, 0x0BFC, 0x0800, 0x0000 }, /* 在 */
  { 0x0000, 0x7FFC, 0x6004, 0x6004, 0x67E4, 0x6424, 0x6424, 0x6424, 0x6424, 0x67E4, 0x6004, 0x6004, 0x7FFC, 0x6004, 0x6004, 0x0000 }, /* 回 */
  { 0x0000, 0x1040, 0x1040, 0x3FFC, 0x69A0, 0x4F80, 0x06C0, 0x0C60, 0x3FF8, 0x600C, 0x0000, 0x1820, 0x1820, 0x1FE0, 0x1820, 0x0000 }, /* 答 */
  { 0x0000, 0x0180, 0x0100, 0x0180, 0x3FFC, 0x2184, 0x2184, 0x2184, 0x3FFC, 0x2184, 0x0100, 0x0180, 0x0180, 0x0180, 0x0100, 0x0000 }, /* 中 */
  { 0x0000, 0x1FF8, 0x1118, 0x1108, 0x1FD8, 0x1998, 0x1108, 0x1FF8, 0x0000, 0x0D80, 0x2C80, 0x2C0C, 0x6C14, 0x47F0, 0x0000, 0x0000 }, /* 思 */
  { 0x0000, 0x0300, 0x0310, 0x0FF0, 0x0360, 0x3FFC, 0x0180, 0x03F8, 0x0F00, 0x3980, 0x21F8, 0x0010, 0x0030, 0x00E0, 0x0000, 0x0000 }  /* 考 */
};
static const char ZH_ANSWER[] = "\xE6\xA8\xA1\xE5\x9E\x8B\xE6\xAD\xA3\xE5\x9C\xA8\xE5\x9B\x9E\xE7\xAD\x94\xE4\xB8\xAD"; /* 模型正在回答中 */
static const char ZH_SIKAO[]  = "\xE6\x80\x9D\xE8\x80\x83\xE4\xB8\xAD"; /* 思考中 */
/* 汉字 UTF-8 三字节 -> 字库下标 */
static const uint8_t ZH_MAP[][4] = {
  { 0xE6, 0xA8, 0xA1, 0 },  /* 模 */
  { 0xE5, 0x9E, 0x8B, 1 },  /* 型 */
  { 0xE6, 0xAD, 0xA3, 2 },  /* 正 */
  { 0xE5, 0x9C, 0xA8, 3 },  /* 在 */
  { 0xE5, 0x9B, 0x9E, 4 },  /* 回 */
  { 0xE7, 0xAD, 0x94, 5 },  /* 答 */
  { 0xE4, 0xB8, 0xAD, 6 },  /* 中 */
  { 0xE6, 0x80, 0x9D, 7 },  /* 思 */
  { 0xE8, 0x80, 0x83, 8 }   /* 考 */
};
int zhIndex(const uint8_t* p) {
  for (int i = 0; i < 9; i++)
    if (p[0] == ZH_MAP[i][0] && p[1] == ZH_MAP[i][1] && p[2] == ZH_MAP[i][2]) return ZH_MAP[i][3];
  return -1;
}
/* 画一串汉字(全部 3 字节 UTF-8), 水平居中, 16x16, 字距 2px (步进18) */
void drawZhStr(const char* s, int y) {
  int n = 0;
  for (const char* p = s; *p; p += 3) n++;
  int x = (128 - (n * 18 - 2)) / 2;
  for (const char* p = s; *p; p += 3) {
    int idx = zhIndex((const uint8_t*)p);
    if (idx >= 0) {
      for (int r = 0; r < 16; r++) {
        uint16_t row = ZH_FONT[idx][r];
        for (int c = 0; c < 16; c++)
          if (row & (1 << (15 - c))) display.drawPixel(x + c, y + r, SSD1306_WHITE);
      }
    }
    x += 18;
  }
}
/* 三个小方块点, 依次点亮-熄灭(空心表示灭), 每个点都有完整闪烁过程 */
void drawBlinkDots(int x, int y, int tick) {
  for (int i = 0; i < 3; i++) {
    if (((tick + i) % 3) == 0) display.fillRect(x + i * 8, y, 5, 5, SSD1306_WHITE);
    else                       display.drawRect(x + i * 8, y, 5, 5, SSD1306_WHITE);
  }
}

/* ============ 播放界面: 模型正在回答中 + 底部余额 ============
   注意: 播放中不能刷新动画, display.display() 走 I2C 整帧 ~30ms,
   插在音频中间会造成断音。所以此屏静态。*/
void drawAnswering() {
  if (!screenOK) return;
  display.clearDisplay();
  drawTopBar();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 13);
  display.print("DeepSeek");
  drawZhStr(ZH_ANSWER, 22);
  /* 底部余额 */
  display.setCursor(0, 52);
  display.print("BALANCE ");
  display.print(g_balance.length() > 0 ? g_balance.c_str() : "--.--");
  display.print(" CNY");
  updatePeriodLed();                  /* 高峰红 / 低谷绿 */
  display.display();
}

/* ============ 等待动画: 思考中 + 三点闪烁 + 循环进度条 ============
   在等服务器返回期间调用, 进度是假的, 只为了让屏幕有动静。 */
void drawWaiting(const char* sub) {
  if (!screenOK) return;
  (void)sub;                          /* v32: 统一显示 思考中 */
  display.clearDisplay();
  drawTopBar();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 13);
  display.print("DeepSeek");

  static int tick = 0;
  tick++;
  drawZhStr("思考中", 22);
  drawBlinkDots(44 + 3 * 14 + 4, 26, tick);

  /* 底部循环进度条 */
  static int prog = 0;
  prog = (prog + 6) % 130;
  if (prog > 120) prog = 0;
  display.drawRect(0, 56, 124, 6, SSD1306_WHITE);
  if (prog > 0) display.fillRect(2, 57, prog, 4, SSD1306_WHITE);

  display.display();
}

/* RGB 灯: 1=高峰(红) 0=低谷(绿) -1=未知(灭) */
void setLedByPeriod(int period) {
  if (period == 1)      pixels.setPixelColor(0, pixels.Color(40, 0, 0));
  else if (period == 0) pixels.setPixelColor(0, pixels.Color(0, 40, 0));
  else                  pixels.clear();
  pixels.show();
}

/* ============ v33 高峰/低谷灯 (移植自余额屏) ============
   DeepSeek 计价高峰: 工作日 9:00-12:00 和 14:00-18:00 (北京时间)
   高峰 -> 红灯, 低谷 -> 绿灯, 时间未同步 -> 灭 */
bool timeReady = false;
bool isPeakHour() {
  if (!timeReady) return false;
  time_t now = time(nullptr);
  struct tm ti;
  localtime_r(&now, &ti);
  bool weekday = (ti.tm_wday >= 1 && ti.tm_wday <= 5);
  bool morning = (ti.tm_hour >= 9 && ti.tm_hour < 12);
  bool afternoon = (ti.tm_hour >= 14 && ti.tm_hour < 18);
  return weekday && (morning || afternoon);
}
void updatePeriodLed() {
  /* v50: 菜单里可强制 红/绿/关, 断电记忆 */
  if (g_ledMode == 3)      { setLedByPeriod(-1); return; }
  if (g_ledMode == 1)      { setLedByPeriod(1);  return; }
  if (g_ledMode == 2)      { setLedByPeriod(0);  return; }
  if (!timeReady && time(nullptr) > 100000) timeReady = true;
  if (!timeReady)          setLedByPeriod(-1);
  else if (isNightTime())  setLedByPeriod(-1);      /* v42: 睡觉时间关灯 */
  else if (isPeakHour())   setLedByPeriod(1);       /* 高峰红 */
  else                     setLedByPeriod(0);       /* 低谷绿 */
}

/* ================== I2S ================== */
void setupMicI2S() {
  i2s_config_t c = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = sampleRate,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_STAND_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8, .dma_buf_len = 64,
    .use_apll = false, .tx_desc_auto_clear = false, .fixed_mclk = 0
  };
  i2s_pin_config_t p = {
    .bck_io_num = I2S_MIC_SCK, .ws_io_num = I2S_MIC_WS,
    .data_out_num = I2S_PIN_NO_CHANGE, .data_in_num = I2S_MIC_SD
  };
  i2s_driver_install(I2S_MIC_PORT, &c, 0, NULL);
  i2s_set_pin(I2S_MIC_PORT, &p);
}

void setupSpkI2S(int rate) {
  i2s_config_t c = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = rate,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = I2S_COMM_FORMAT_STAND_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 6, .dma_buf_len = 240,   /* 参考小智: 缓冲太小会导致欠载爆音 */
    .use_apll = false, .tx_desc_auto_clear = true, .fixed_mclk = 0
  };
  i2s_pin_config_t p = {
    .bck_io_num = I2S_SPK_BCLK, .ws_io_num = I2S_SPK_LRC,
    .data_out_num = I2S_SPK_DIN, .data_in_num = I2S_PIN_NO_CHANGE
  };
  i2s_driver_install(I2S_SPK_PORT, &c, 0, NULL);
  i2s_set_pin(I2S_SPK_PORT, &p);
  i2s_set_sample_rates(I2S_SPK_PORT, rate);
}
/* ================== 采样块: 读一块, 返回能量 ================== */
int readBlockEx(int16_t* dest, int maxWrite, int* outCnt) {
  int32_t in[320];
  size_t n = 0;
  esp_err_t err = i2s_read(I2S_MIC_PORT, in, sizeof(in), &n, BLOCK_MS / portTICK_PERIOD_MS);
  if (outCnt) *outCnt = 0;
  if (err != ESP_OK || n == 0) return -1;
  int cnt = n / 4;
  long sum = 0;
  int wrote = 0;
  for (int i = 0; i < cnt; i++) {
    int32_t v = in[i] >> 14;
    long a = v < 0 ? -v : v;
    sum += a;
    if (dest && wrote < maxWrite) dest[wrote++] = (int16_t)v;
  }
  if (outCnt) *outCnt = wrote;
  return (int)(sum / (cnt > 0 ? cnt : 1));
}

/* ================== 录音(带倒计时显示) ================== */
long recordSpeech(int baseline) {
  long len = 0;
  memset(pcmBuf, 0, 64);              /* 清掉开头的 WAV 头区域, 防止发出去是旧数据 */
  int stopCount = 0;
  unsigned long lastScreen = 0;
  int stopThreshold = (int)(baseline * STOP_RATIO);

  while (len < MAX_SAMPLES) {
    int got = 0;
    int e = readBlockEx(pcmBuf + 22 + len, (int)(MAX_SAMPLES - len), &got);
    if (got > 0) len += got;
    if (e < 0) { delay(5); continue; }

    if (e < stopThreshold) stopCount++; else stopCount = 0;

    if (millis() - lastScreen > 120) {
      lastScreen = millis();
      if (screenOK) {
        display.clearDisplay();
        display.setTextColor(SSD1306_WHITE);
        drawTopBar();                       /* 顶栏常驻 */

        display.setTextSize(1);
        display.setCursor(0, 12);
        display.print("REC  ");
        display.print(len / (float)sampleRate, 1);
        display.print(" s");

        display.setTextSize(2);
        display.setCursor(0, 24);
        if (stopCount > 0) {
          float left = (STOP_BLOCKS - stopCount) * (BLOCK_MS / 1000.0);
          display.print("STOP ");
          display.print(left, 1);
          display.print("s");
        } else {
          display.print(">>>");
        }

        long barLen = e / 30;
        if (barLen > 120) barLen = 120;
        display.drawRect(0, 52, 120, 8, SSD1306_WHITE);
        display.fillRect(0, 52, barLen, 8, SSD1306_WHITE);
        display.display();
      }
    }
    if (stopCount >= STOP_BLOCKS) break;
  }
  return len;
}

/* ================== 生成 WAV(16bit mono) ==================
   做法: 在录音缓冲区前面预留的 44 字节里写 WAV 头,
   然后直接把整块(头+数据)当 WAV 发出去, 不再额外申请内存。 */
uint8_t* buildWav(const int16_t* pcm, long samples, long* outLen) {
  long dataBytes = samples * 2;
  long total = 44 + dataBytes;

  uint8_t* w = (uint8_t*)pcmBuf;      /* 直接用录音缓冲, 开头已经留了 44 字节 */

  long idx = 0;
  memcpy(w + idx, "RIFF", 4); idx += 4;
  uint32_t fileLen = total - 8; memcpy(w + idx, &fileLen, 4); idx += 4;
  memcpy(w + idx, "WAVE", 4); idx += 4;
  memcpy(w + idx, "fmt ", 4); idx += 4;
  uint32_t fmtSize = 16; memcpy(w + idx, &fmtSize, 4); idx += 4;
  uint16_t fmt = 1;     memcpy(w + idx, &fmt, 2); idx += 2;
  uint16_t ch = 1;      memcpy(w + idx, &ch, 2); idx += 2;
  uint32_t sr = sampleRate; memcpy(w + idx, &sr, 4); idx += 4;
  uint32_t byteRate = sampleRate * 2; memcpy(w + idx, &byteRate, 4); idx += 4;
  uint16_t blockAlign = 2; memcpy(w + idx, &blockAlign, 2); idx += 2;
  uint16_t bits = 16;   memcpy(w + idx, &bits, 2); idx += 2;
  memcpy(w + idx, "data", 4); idx += 4;
  uint32_t dataLen = dataBytes; memcpy(w + idx, &dataLen, 4); idx += 4;
  /* 数据本来就在头后面, 不需要再拷贝 */

  *outLen = total;
  return w;
}

/* ================== 播放 16bit PCM, 指定采样率 ==================
   v30: 数字音量 -6dB (乘 0.5)。
   TTS 原文件峰值常贴近满幅, 满音量 + 功放默认 9dB 增益会削波炸麦。
   还炸麦 -> 改 0.3; 太小声 -> 改 0.7。*/
void playPCM(const int16_t* data, long samples, int rate) {
  if (g_muted) { Serial.println(">>> muted, skip playback"); return; }   /* v35 */
  i2s_set_sample_rates(I2S_SPK_PORT, rate);
  delay(10);                       /* 等时钟稳定 */
  int32_t out[128];
  size_t written;
  int peak = 0;
  for (long i = 0; i < samples; i += 64) {
    int cnt = (samples - i > 64) ? 64 : (samples - i);
    for (int j = 0; j < cnt; j++) {
      int32_t s = data[i + j];
      int a = s < 0 ? -s : s;
      if (a > peak) peak = a;
      int32_t v = (int32_t)(s * g_gain) << 16;
      out[j * 2] = v;
      out[j * 2 + 1] = v;
    }
    i2s_write(I2S_SPK_PORT, out, cnt * 2 * 4, &written, portMAX_DELAY);
  }
  Serial.printf(">>> playPCM done, peak=%d (满幅32767, 接近就说明在削波)\n", peak);
  int32_t zero[128] = {0};
  for (int k = 0; k < 20; k++) {
    i2s_write(I2S_SPK_PORT, zero, sizeof(zero), &written, portMAX_DELAY);
  }
}
/* ================== HTTP 小工具: 解析 WAV 头 ================== */
/* 从 WAV 字节里找出 data 块起点和采样率, 返回样本数 */
/* ============ 开机自检音 ============
   播 3 声"嘀"(1000Hz), 每声 120ms, 间隔 150ms。
   能听到干净的三声嘀 => 喇叭 + 接线完全正常, 问题只在数据。
   听到沙沙声/爆音    => 功放或接线有问题。
*/
void playSelfTest() {
  Serial.println(">>> SELF TEST: 3 beeps");
  if (screenOK) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 20);
    display.println("SPEAKER TEST");
    display.setCursor(0, 36);
    display.println("3 beeps...");
    display.display();
  }

  i2s_set_sample_rates(I2S_SPK_PORT, 16000);

  const int nSamples = 16000 * 120 / 1000;    /* 120ms */
  const int gapSamples = 16000 * 150 / 1000;  /* 150ms 静音 */
  int32_t buf[128];
  size_t written;

  for (int beep = 0; beep < 3; beep++) {
    /* 发声 */
    for (int i = 0; i < nSamples; ) {
      int cnt = 0;
      while (cnt < 64 && i < nSamples) {
        double phase = 2.0 * PI * 1000.0 * i / 16000.0;
        int16_t v = (int16_t)(sin(phase) * 10000);
        buf[cnt * 2] = (int32_t)v << 16;
        buf[cnt * 2 + 1] = (int32_t)v << 16;
        cnt++; i++;
      }
      i2s_write(I2S_SPK_PORT, buf, cnt * 2 * 4, &written, portMAX_DELAY);
    }
    /* 静音 */
    memset(buf, 0, sizeof(buf));
    for (int i = 0; i < gapSamples; i += 64) {
      i2s_write(I2S_SPK_PORT, buf, 64 * 2 * 4, &written, portMAX_DELAY);
    }
  }

  /* 尾部再补一点静音, 排空 DMA */
  memset(buf, 0, sizeof(buf));
  for (int k = 0; k < 30; k++) {
    i2s_write(I2S_SPK_PORT, buf, sizeof(buf), &written, portMAX_DELAY);
  }
  Serial.println(">>> SELF TEST done");
}

long parseWav(uint8_t* buf, long len, int* rate, long* dataOffset) {
  *rate = 24000;
  *dataOffset = 0;
  if (len < 44) return 0;

  /* 服务器用 Transfer-Encoding: chunked, 正文前面有 "1dc\r\n" 这样的块头。
     直接在缓冲里搜 "RIFF" 的位置, 从那里开始解析。 */
  long base = -1;
  for (long i = 0; i + 4 <= len && i < 4096; i++) {
    if (buf[i] == 'R' && buf[i+1] == 'I' && buf[i+2] == 'F' && buf[i+3] == 'F') {
      base = i;
      break;
    }
  }
  if (base < 0) {
    Serial.println("parseWav: no RIFF found");
    return 0;
  }
  Serial.printf("parseWav: RIFF at %ld\n", base);

  uint8_t* w = buf + base;
  long wlen = len - base;

  long pos = 12;
  while (pos + 8 < wlen) {
    if (memcmp(w + pos, "fmt ", 4) == 0) {
      uint32_t r; memcpy(&r, w + pos + 12, 4);
      if (r > 1000 && r < 100000) *rate = (int)r;
      /* v30: 打印格式, 位深!=16 或声道!=1 时播放会出错 */
      uint16_t fmtCh = 0, fmtBits = 0;
      memcpy(&fmtCh,  w + pos + 10, 2);
      memcpy(&fmtBits, w + pos + 22, 2);
      Serial.printf("parseWav: fmt ch=%u rate=%u bits=%u\n",
                    fmtCh, (unsigned)r, fmtBits);
    }
    uint32_t sz; memcpy(&sz, w + pos + 4, 4);
    if (sz == 0xFFFFFFFFUL) {            /* 流式未定长, 后面不会再有块 */
      if (memcmp(w + pos, "data", 4) == 0) {
        *dataOffset = base + pos + 8;
        long avail = len - *dataOffset;
        if (avail > 0) {
          Serial.printf("parseWav: data at %ld, avail=%ld (streaming)\n", *dataOffset, avail);
          return avail / 2;
        }
      }
      break;
    }
    if (memcmp(w + pos, "data", 4) == 0) {
      *dataOffset = base + pos + 8;
      long avail = len - *dataOffset;          /* 实际还剩多少字节 */
      if (avail <= 0) break;
      /* 流式 WAV 的 sz 常是 0xFFFFFFFF, 不能直接比较(转 long 会变 -1),
         只在实际数据更短时才采用 sz */
      if (sz != 0xFFFFFFFFUL && (long)sz < avail) avail = (long)sz;
      Serial.printf("parseWav: data at %ld, avail=%ld bytes, sz=%lu\n",
                    *dataOffset, avail, (unsigned long)sz);
      return avail / 2;              /* 16bit 单声道 */
    }
    pos += 8 + sz + (sz & 1);
  }
  Serial.println("parseWav: no data chunk");
  return 0;
}


/* ============ 读完整 HTTP 响应 ============
   问题: 用 while(client.available()) 会在"头读完了但正文还没到"时提前退出。
   做法: 先读到 \r\n\r\n, 解析 Content-Length, 再精确读够正文长度。 */
String readHttpResponse(WiFiClientSecure& client, unsigned long timeoutMs) {
  String resp = "";
  unsigned long t0 = millis();

  /* 阶段一: 读响应头 */
  while (resp.indexOf("\r\n\r\n") < 0) {
    if (client.available()) { resp += (char)client.read(); t0 = millis(); }
    else {
      if (!client.connected() && !client.available()) break;
      if (millis() - t0 > timeoutMs) break;
      if (millis() - g_waitLast > 150) { g_waitLast = millis(); drawWaiting(g_waitSub); }
      delay(5);
    }
    if (resp.length() > 4000) break;
  }

  int hdrEnd = resp.indexOf("\r\n\r\n");
  if (hdrEnd < 0) return resp;               /* 头都没读全, 原样返回 */
  int bodyStart = hdrEnd + 4;
  long bodyHave = resp.length() - bodyStart;

  /* 解析 Content-Length */
  long want = -1;
  int cl = resp.indexOf("Content-Length:");
  if (cl < 0) cl = resp.indexOf("content-length:");
  if (cl >= 0) {
    want = 0;
    for (int i = cl + 15; i < hdrEnd; i++) {
      char c = resp[i];
      if (c >= '0' && c <= '9') want = want * 10 + (c - '0');
      else if (c == ' ') continue;
      else break;
    }
  }

  if (want < 0) {
    /* 没有 Content-Length(分块传输), 读到连接关闭为止 */
    while (client.connected() || client.available()) {
      if (client.available()) { resp += (char)client.read(); t0 = millis(); }
      else { if (millis() - t0 > timeoutMs) break; delay(5); }
      if (resp.length() > 20000) break;
    }
    return resp;
  }

  /* 按 Content-Length 读够 */
  while (bodyHave < want) {
    if (client.available()) {
      resp += (char)client.read();
      bodyHave++;
      t0 = millis();
    } else {
      if (!client.connected() && !client.available()) break;
      if (millis() - t0 > timeoutMs) break;
      if (millis() - g_waitLast > 150) { g_waitLast = millis(); drawWaiting(g_waitSub); }
      delay(5);
    }
  }
  return resp;
}

/* ================== ASR: WAV -> 文字 ================== */
String asrRequest(uint8_t* wav, long wavLen) {
  WiFiClientSecure client;
  client.setInsecure();
  client.setTimeout(20000);

  if (client.connect("api.deepseek.com", 443) != 1) {
    Serial.println("ASR: connect fail");
    return "";
  }

  String boundary = "----ESP32Boundary7d3f";

  String head = "--" + boundary + "\r\n";
  head += "Content-Disposition: form-data; name=\"file\"; filename=\"speech.wav\"\r\n";
  head += "Content-Type: audio/wav\r\n\r\n";

  String tail = "\r\n--" + boundary + "--\r\n";

  long totalLen = head.length() + wavLen + tail.length();

  /* 请求头: 全部用 print, 自己控制 \r\n, 不要用 println(会多出换行) */
  String req = "";
  req += "POST /v1/tools/asr HTTP/1.1\r\n";
  req += "Host: api.deepseek.com\r\n";
  req += "Authorization: Bearer " + g_key + "\r\n";
  req += "Content-Type: multipart/form-data; boundary=" + boundary + "\r\n";
  req += "Content-Length: " + String(totalLen) + "\r\n";
  req += "Connection: close\r\n";
  req += "\r\n";
  client.print(req);

  /* body: 头 + WAV + 尾
     关键: client.write() 一次发不完(实测只发 16KB), 必须循环写到全部发完 */
  client.print(head);

  long totalSent = 0;
  unsigned long writeStart = millis();
  while (totalSent < wavLen) {
    size_t n = client.write(wav + totalSent, wavLen - totalSent);
    if (n == 0) {
      /* 写不动了, 等一下再试; 连续 5 秒无进展就放弃 */
      delay(10);
      if (millis() - writeStart > 5000 && totalSent == 0) break;
      if (millis() - writeStart > 30000) break;
      continue;
    }
    totalSent += n;
    writeStart = millis();
    /* 期间刷新等待动画, 不然屏幕会僵住 */
    if (millis() - g_waitLast > 150) { g_waitLast = millis(); drawWaiting(g_waitSub); }
  }

  client.print(tail);
  client.flush();
  Serial.printf("ASR: wavLen=%ld sent=%ld boundary=%s\n", wavLen, totalSent, boundary.c_str());

  /* 读响应 */
  unsigned long t0 = millis();
  while (!client.available() && millis() - t0 < 20000) {
    if (millis() - g_waitLast > 150) { g_waitLast = millis(); drawWaiting(g_waitSub); }
    delay(10);
  }

  String resp = readHttpResponse(client, 20000);
  Serial.printf("ASR: got %d bytes, connected=%d\n", resp.length(), client.connected());
  client.stop();
  return resp;
}

/* 从 ASR 响应里抠出 text 字段 */
String extractJsonField(const String& json, const char* key) {
  String k = String("\"") + key + "\":";
  int p = json.indexOf(k);
  if (p < 0) return "";
  p += k.length();
  while (p < json.length() && json[p] == ' ') p++;
  if (p >= json.length()) return "";

  String result = "";
  if (json[p] == '"') {
    p++;
    while (p < json.length()) {
      char c = json[p];
      if (c == '\\' && p + 1 < json.length()) {
        char n = json[p + 1];
        if (n == 'u') {
          long cp = strtol(json.substring(p + 2, p + 6).c_str(), NULL, 16);
          if (cp < 128) result += (char)cp;
          else if (cp < 0x800) {
            result += (char)(0xC0 | (cp >> 6));
            result += (char)(0x80 | (cp & 0x3F));
          } else {
            result += (char)(0xE0 | (cp >> 12));
            result += (char)(0x80 | ((cp >> 6) & 0x3F));
            result += (char)(0x80 | (cp & 0x3F));
          }
          p += 6;
          continue;
        }
        result += n;
        p += 2;
        continue;
      }
      if (c == '"') break;
      result += c;
      p++;
    }
  } else {
    int e = p;
    while (e < json.length() && json[e] != ',' && json[e] != '}') e++;
    result = json.substring(p, e);
  }
  return result;
}

/* ================== 对话 ================== */
bool chatRequest(const String& userText, String& reply) {
  WiFiClientSecure client;
  client.setInsecure();
  client.setTimeout(30000);

  if (client.connect("api.deepseek.com", 443) != 1) {
    Serial.println("CHAT: connect fail");
    return false;
  }

  /* 组 JSON */
  String body = "{\"model\":\"" + String(MODEL_CHAT) + "\",";
  body += "\"thinking\":{\"type\":\"disabled\"},";   /* 关思考, 省钱 */
  body += "\"max_tokens\":300,";
  body += "\"messages\":[";
  body += "{\"role\":\"system\",\"content\":\"你是一个语音助手。你的回答会被直接转成语音朗读给用户听, 所以必须口语化。规则: 一到三句话说完; 不要用 markdown、星号、井号、列表、括号; 不要出现表情符号; 不要写套话, 直接回答; 数字用口语写出来。\"}";

  for (int i = 0; i < historyCount; i++) {
    body += ",{\"role\":\"";
    body += ((i % 2 == 0) ? "user" : "assistant");   /* 必须加括号: += 优先级高于 ?: */
    body += "\",\"content\":";
    /* 转义: 只处理引号和反斜杠 */
    String c = history[i];
    c.replace("\\", "\\\\");
    c.replace("\"", "\\\"");
    body += "\"" + c + "\"}";      /* 补上结束的 } */
  }

  body += ",{\"role\":\"user\",\"content\":";
  String u = userText;
  u.replace("\\", "\\\\");
  u.replace("\"", "\\\"");
  body += "\"" + u + "\"}";
  body += "],\"stream\":false}";

  /* 调试: 把实际发出的 JSON 打出来, 分段打印避免串口卡住 */
  Serial.printf(">>> JSON len=%d historyCount=%d\n", body.length(), historyCount);
  for (int k = 0; k < (int)body.length(); k += 200) {
    int e = k + 200;
    if (e > (int)body.length()) e = body.length();
    Serial.println("J|" + body.substring(k, e));
    delay(5);
  }
  Serial.println(">>> JSON END");

  client.println("POST /chat/completions HTTP/1.1");
  client.println("Host: api.deepseek.com");
  client.print("Authorization: Bearer ");
  client.println(g_key);
  client.println("Content-Type: application/json");
  client.print("Content-Length: ");
  client.println(body.length());
  client.println("Connection: close");
  client.println();
  client.print(body);

  String resp = readHttpResponse(client, 30000);
  client.stop();

  Serial.printf("CHAT resp total=%d bytes\n", resp.length());
  if (resp.length() > 0) {
    int bodyStart = resp.indexOf("\r\n\r\n");
    Serial.printf("body starts at %d\n", bodyStart);
    for (int i = 0; i < resp.length() && i < 1200; i += 200) {
      Serial.println(resp.substring(i, i + 200));
    }
  }

  reply = extractJsonField(resp, "content");
  if (reply.length() == 0) {
    Serial.println("CHAT fail: no content field");
    return false;
  }

  /* token 统计 */
  lastPromptTok = extractJsonField(resp, "prompt_tokens").toInt();
  lastCompTok = extractJsonField(resp, "completion_tokens").toInt();
  lastCacheHit = extractJsonField(resp, "prompt_cache_hit_tokens").toInt();
  lastCacheMiss = extractJsonField(resp, "prompt_cache_miss_tokens").toInt();
  ctxTokens = extractJsonField(resp, "total_tokens").toInt();
  return true;
}
/* ================== 去掉分块传输(chunked)的块头 ==================
   服务器用 Transfer-Encoding: chunked, 音频被切成很多块,
   每块前面有一行十六进制长度(如 "1e9\r\n"), 块尾有 \r\n。
   这些字符混在音频里, 任何采样率下都会"炸麦"。
   这里把它们剥掉, 把纯音频数据搬到开头。 */
long dechunkInPlace(uint8_t* buf, long len) {
  /* 如果开头就是 RIFF, 说明服务器没分块, 原样返回 */
  if (len >= 4 && buf[0] == 'R' && buf[1] == 'I' && buf[2] == 'F' && buf[3] == 'F') {
    Serial.println("dechunk: already clean (RIFF at 0)");
    return len;
  }

  long r = 0, w = 0;
  int chunks = 0;
  while (r < len) {
    long ls = r;
    while (r < len && buf[r] != '\n') r++;
    if (r >= len) break;
    long le = r;
    r++;

    long sz = 0;
    bool ok = false;
    for (long i = ls; i < le; i++) {
      char c = (char)buf[i];
      int d;
      if (c >= '0' && c <= '9') d = c - '0';
      else if (c >= 'a' && c <= 'f') d = c - 'a' + 10;
      else if (c >= 'A' && c <= 'F') d = c - 'A' + 10;
      else if (c == '\r') continue;
      else { ok = false; break; }
      sz = sz * 16 + d;
      ok = true;
    }
    if (!ok || sz <= 0) break;

    if (r + sz > len) sz = len - r;
    if (sz > 0) memmove(buf + w, buf + r, sz);
    w += sz;
    r += sz;
    while (r < len && (buf[r] == '\r' || buf[r] == '\n')) r++;
    chunks++;
  }
  Serial.printf("dechunk: %d chunks, %ld -> %ld bytes\n", chunks, len, w);
  return w;
}

/* ================== TTS: 文字 -> WAV 音频 ================== */
bool ttsRequest(const String& text, uint8_t** outBuf, long* outLen) {
  WiFiClientSecure client;
  client.setInsecure();
  client.setTimeout(30000);

  if (client.connect("api.deepseek.com", 443) != 1) {
    Serial.println("TTS: connect fail");
    return false;
  }

  String t = text;
  t.replace("\\", "\\\\");
  t.replace("\"", "\\\"");
  t.replace("\n", " ");

  String body = "{\"text\":\"" + t + "\",\"voice_id\":\"";
  body += TTS_VOICE;
  body += "\",\"format\":\"wav\"}";

  client.println("POST /v1/tools/tts HTTP/1.1");
  client.println("Host: api.deepseek.com");
  client.print("Authorization: Bearer ");
  client.println(g_key);
  client.println("Content-Type: application/json");
  client.print("Content-Length: ");
  client.println(body.length());
  client.println("Connection: close");
  client.println();
  client.print(body);

  /* 等响应头 */
  unsigned long t0 = millis();
  while (!client.available() && millis() - t0 < 30000) {
    if (millis() - g_waitLast > 150) { g_waitLast = millis(); drawWaiting(g_waitSub); }
    delay(10);
  }

  String header = "";
  while (client.available() && header.length() < 2000) {
    char c = client.read();
    header += c;
    if (header.endsWith("\r\n\r\n")) break;
  }

  if (header.indexOf("200") < 0) {
    Serial.println("TTS HTTP: " + header.substring(0, 120));
    client.stop();
    return false;
  }

  /* 读 body: 有 PSRAM 用 512KB, 没有就用 200KB(约 4 秒 24kHz 音频, 够短回复用) */
  long cap = psramFound() ? (512 * 1024) : (200 * 1024);
  uint8_t* buf = (uint8_t*)(psramFound() ? ps_malloc(cap) : malloc(cap));
  if (!buf) {
    Serial.printf("TTS: alloc %ld failed (psram=%d, free=%d)\n",
                  cap, psramFound(), ESP.getFreeHeap());
    client.stop();
    return false;
  }

  long got = 0;
  t0 = millis();
  while (millis() - t0 < 30000) {
    if (millis() - g_waitLast > 150) { g_waitLast = millis(); drawWaiting(g_waitSub); }
    if (client.available()) {
      long want = cap - got; if (want > 1024) want = 1024;
      int n = client.read(buf + got, want);
      if (n > 0) got += n;
      if (got >= cap) break;
      t0 = millis();
    } else {
      if (!client.connected() && !client.available()) break;
      delay(5);
    }
  }
  client.stop();

  Serial.printf("TTS got %ld bytes (含响应头+块头)\n", got);
  if (got < 1000) { free(buf); return false; }

  /* v31: 响应头在上面的 String header 循环里已经读完了,
     buf 里就是纯正文(可能带 chunked 块头), 直接处理。
     ⚠️ 千万别再找 \r\n\r\n: 分块正文前 2000 字节里没有它,
        找了就会误判 "no body" 把语音扔掉 (v30 无声的根因)。 */
  long bodyLen = got;

  /* 剥掉分块头 */
  long cleanLen = dechunkInPlace(buf, bodyLen);
  Serial.printf("TTS clean %ld bytes, first4=%02X%02X%02X%02X\n",
                cleanLen, buf[0], buf[1], buf[2], buf[3]);

  /* 兜底: dechunk 没产出合法 WAV 时, 回退 v26 的做法:
     在正文里搜 RIFF, 从那里开始当 WAV 播(可能带块头杂音, 但至少出声) */
  if (cleanLen < 1000 || !(buf[0] == 'R' && buf[1] == 'I' && buf[2] == 'F' && buf[3] == 'F')) {
    for (long i = 0; i + 4 <= bodyLen && i < 65536; i++) {
      if (buf[i] == 'R' && buf[i+1] == 'I' && buf[i+2] == 'F' && buf[i+3] == 'F') {
        if (i > 0) memmove(buf, buf + i, bodyLen - i);
        cleanLen = bodyLen - i;
        Serial.printf("TTS fallback: RIFF at %ld, use raw from there\n", i);
        break;
      }
    }
  }

  if (cleanLen < 1000) { free(buf); return false; }

  *outBuf = buf;
  *outLen = cleanLen;
  return true;
}

/* ================== 费用计算 ================== */
/* deepseek-flash 空闲时段: 输入 1元/百万, 输出 4元/百万 */
float calcCost(long pt, long ct) {
  return pt / 1000000.0 * 1.0 + ct / 1000000.0 * 4.0;
}

void showCostScreen() {
  if (!screenOK) return;
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  float cost = calcCost(lastPromptTok, lastCompTok);

  drawTopBar();                       /* 顶栏: CTX / WiFi */

  /* 中间大字: 本轮花费 */
  display.setTextSize(2);
  display.setCursor(0, 16);
  display.print(cost, 4);
  display.setTextSize(1);
  display.setCursor(66, 22);
  display.print("CNY");

  /* 今日累计 (v32: 去掉 CACHE/IN/OUT, 只留看得懂的钱) */
  display.setCursor(0, 42);
  display.print("SUM ");
  display.print(todayCost, 4);
  display.print(" CNY today");

  display.display();
}

/* ================== 查余额 ================== */
bool fetchBalance() {
  if (g_key.length() < 20) return false;   /* v50: 没密钥不查 */
  WiFiClientSecure client;
  client.setInsecure();
  client.setTimeout(10000);

  if (client.connect("api.deepseek.com", 443) != 1) return false;

  String req = "";
  req += "GET /user/balance HTTP/1.1\r\n";
  req += "Host: api.deepseek.com\r\n";
  req += "Authorization: Bearer " + g_key + "\r\n";
  req += "Connection: close\r\n\r\n";
  client.print(req);

  String resp = readHttpResponse(client, 10000);
  client.stop();

  int p = resp.indexOf("\"total_balance\":\"");
  if (p < 0) return false;
  p += 17;
  int e = resp.indexOf('"', p);
  if (e < 0) return false;
  g_balance = resp.substring(p, e);
  Serial.print(">>> balance = "); Serial.println(g_balance);
  return true;
}

/* ================== 待机屏: 显示余额 ================== */
void showIdle() {
  if (!screenOK) return;
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  /* v44: 顶栏 = 时间 + 上下文占用(左上) / WiFi(右上) */
  drawTopBar();

  /* 大字余额 */
  display.setTextSize(3);
  display.setCursor(0, 14);
  if (g_balance.length() > 0) display.print(g_balance.c_str());
  else display.print("--.--");

  /* 右侧小字 CNY */
  display.setTextSize(1);
  display.setCursor(96, 36);
  display.print("CNY");

  if (g_key.length() >= 20) {
    /* 今日花费 */
    display.setCursor(0, 44);
    display.print("TODAY ");
    display.print(todayCost, 4);
    display.print(" CNY");
    /* 上下文轮数提醒 (小字, 底部左) */
    display.setCursor(0, 56);
    display.print("CTX ");
    display.print(ctxTokens);
    display.print("/4K  T");
    display.print(todayTurns);
  } else {
    /* v51: 没密钥时大字下方提醒去哪设 (版本号挪到角落常驻) */
    display.setCursor(0, 44);
    display.print("NO KEY");
    display.setCursor(0, 56);
    display.print(WiFi.localIP().toString());
    display.print(":8080");
  }

  /* 右下角常驻小字版本号, 不管有没有密钥都显示 */
  display.setCursor(106, 56);
  display.print("v");
  display.print(FW_VER);

  updatePeriodLed();                  /* 高峰红 / 低谷绿 / 夜里灭 */
  display.display();
}

/* ================== WiFi ================== */
bool connectWiFi() {
  /* v55: NVS 里配过网就优先用它 (配网 > 固件里写死的列表) */
  if (g_wifiSsid.length() > 0) {
    wifiMulti.addAP(g_wifiSsid.c_str(), g_wifiPass.c_str());
  }
  int n = sizeof(WIFI_LIST) / sizeof(WIFI_LIST[0]);
  for (int i = 0; i < n; i++) {
    wifiMulti.addAP(WIFI_LIST[i].ssid, WIFI_LIST[i].pass);
  }

  Serial.print("WiFi connecting");
  screen2("WiFi...", "connecting");
  int tries = 0;
  while (wifiMulti.run() != WL_CONNECTED && tries < 40) {
    delay(500);
    Serial.print(".");
    tries++;
  }
  if (wifiMulti.run() == WL_CONNECTED) {
    Serial.println();
    Serial.print("IP: "); Serial.println(WiFi.localIP());
    wifiReady = true;
    configTime(8 * 3600, 0, "ntp.aliyun.com", "ntp2.aliyun.com");  /* v33: 北京时间, 峰谷灯用 */
    return true;
  }
  Serial.println();
  Serial.println("WiFi FAIL");
  return false;
}

/* ================== 校准底噪 ================== */
int calibrate() {
  Serial.println(">>> calibrating, be quiet 2s");
  screen2("CALIBRATE", "be quiet 2s");
  long sum = 0; int cnt = 0;
  unsigned long t0 = millis();
  while (millis() - t0 < CALIB_MS) {
    int c = 0;
    int e = readBlockEx(NULL, 0, &c);
    if (e > 0) { sum += e; cnt++; }
  }
  int base = (cnt > 0) ? (int)(sum / cnt) : 300;
  if (base < 100) base = 100;
  Serial.printf(">>> baseline=%d\n", base);
  return base;
}
/* ================== OTA: 无线升级固件 (v39) ==================
   电脑上一条命令就能升级, 不用插 USB:
     curl -X POST --data-binary "@aibox.ino.bin" http://<板子IP>:8080/update
   传完自动重启, 屏幕上显示百分比。*/
WebServer otaServer(8080);

/* ================== v45: OTA 上传口令 ==================
   没带正确口令的推送一律拒绝(401), 防止同网段别人给你刷固件。
   推送时在网址前面带 user:pass 即可, 例如:
     curl -F "firmware=@aibox.ino.bin" http://aibox:口令@192.168.1.6:8080/update
   想换口令就改下面这行, 重新烧一次。 */
#define OTA_USER "aibox"
#define OTA_PASS "k7m2x9"

bool otaAuthorized() {
  if (otaServer.authenticate(OTA_USER, OTA_PASS)) return true;
  otaServer.requestAuthentication(BASIC_AUTH, "AI Box OTA");
  return false;
}


long g_otaTotal = 0;   /* v52: OTA 推送的总字节(取请求 Content-Length 估算), 0=未知 */

void handleOtaFile() {
  HTTPUpload& up = otaServer.upload();
  if (up.status == UPLOAD_FILE_START) {
    if (!otaAuthorized()) return;      /* v45: 没口令别想刷 */
    Serial.printf(">>> OTA start: %s\n", up.filename.c_str());
    g_otaTotal = otaServer.header("Content-Length").toInt();
    if (!Update.begin(UPDATE_SIZE_UNKNOWN)) { Update.printError(Serial); }
    if (screenOK) {
      display.clearDisplay();
      display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 10); display.print("OTA UPDATE");
      display.display();
    }
  } else if (up.status == UPLOAD_FILE_WRITE) {
    if (Update.write(up.buf, up.currentSize) != up.currentSize) Update.printError(Serial);
    static unsigned long lastDraw = 0;
    if (millis() - lastDraw > 400) {
      lastDraw = millis();
      if (screenOK) {
        display.clearDisplay();
        display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
        display.setCursor(0, 10); display.print("OTA UPDATE");
        display.setTextSize(2); display.setCursor(0, 24);
        display.print(Update.progress() / 1024); display.print("K");

        /* v52: 底部进度条 + 百分比 (总大小取请求 Content-Length 估算) */
        long tot = g_otaTotal > 1000 ? g_otaTotal - 300 : 964L * 1024;
        int pw = (int)(120L * Update.progress() / tot);
        if (pw > 120) pw = 120;
        display.drawRect(0, 44, 124, 10, SSD1306_WHITE);
        if (pw > 0) display.fillRect(2, 46, pw, 6, SSD1306_WHITE);
        display.setTextSize(1);
        display.setCursor(0, 57);
        display.print(100L * Update.progress() / tot);
        display.print("%");
        display.display();
      }
    }
  } else if (up.status == UPLOAD_FILE_END) {
    if (Update.end(true)) {
      Serial.printf(">>> OTA OK, %u bytes, rebooting\n", (unsigned)Update.progress());
    } else {
      Update.printError(Serial);
      Serial.println(">>> OTA FAIL");
    }
  }
}


void handleOtaDone() {
  if (!otaAuthorized()) return;        /* v45: 口令不对直接拒 */
  if (Update.hasError()) {
    otaServer.send(500, "text/plain", "FAIL");
  } else {
    otaServer.send(200, "text/plain", "OK, rebooting");
    delay(800);
    ESP.restart();
  }
}

/* ================== v50: 网页配置 (密钥等) ==================
   浏览器打开 http://盒子IP:8080/config (会要 OTA 口令), 填一次密钥就行。
   密钥存 NVS, 以后刷固件不丢, 固件文件里永不含密钥。 */
void handleConfigPage() {
  if (!otaAuthorized()) return;
  String html = "<!DOCTYPE html><html><head><meta charset='utf-8'>";
  html += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
  html += "<title>AI Box Config</title></head><body style='font-family:sans-serif;max-width:420px;margin:24px auto;padding:0 12px'>";
  html += "<h3>AI Box Config</h3>";
  html += "<p>IP " + WiFi.localIP().toString() + " | fw v" + String(FW_VER) + "</p>";
  html += "<p>DeepSeek Key: <b>";
  html += (g_key.length() >= 20) ? "SET" : "NOT SET!";
  html += "</b></p><form method='POST' action='/config'>";
  html += "<input name='key' style='width:100%;padding:8px' placeholder='sk-...' autocomplete='off'><br><br>";
  html += "<button type='submit' style='padding:8px 24px'>SAVE</button></form>";
  html += "</body></html>";
  otaServer.send(200, "text/html", html);
}

void handleConfigSave() {
  if (!otaAuthorized()) return;
  String k = otaServer.arg("key");
  k.trim();
  if (k.length() < 20) { otaServer.send(400, "text/plain", "key too short"); return; }
  prefs.begin("aibox", false);
  prefs.putString("key", k);
  prefs.end();
  g_key = k;
  Serial.println(">>> key saved via /config");
  otaServer.send(200, "text/plain", "OK, key saved.");
  fetchBalance();     /* v52: 设完密钥立刻把余额刷上屏, 眼见为实 */
  showIdle();
}

void startOtaServer() {
  otaServer.on("/update", HTTP_POST, handleOtaDone, handleOtaFile);
  otaServer.on("/config", HTTP_GET, handleConfigPage);    /* v50: 配置页 */
  otaServer.on("/config", HTTP_POST, handleConfigSave);   /* v50: 保存密钥 */
  otaServer.on("/", HTTP_GET, []() {
    if (!otaAuthorized()) return;
    otaServer.send(200, "text/plain", "AI Box OTA ready (auth ok).\n");
  });
  /* v48: 版本查询接口 —— 电脑上 curl 一下就知道板子在跑哪一版 */
  otaServer.on("/version", HTTP_GET, []() {
    if (!otaAuthorized()) return;
    String s = "v";
    s += FW_VER;
    s += "\n";
    s += "ip ";
    s += WiFi.localIP().toString();
    s += "\n";
    s += "uptime ";
    s += (unsigned long)(millis() / 1000);
    s += "s\n";
    s += "free ";
    s += ESP.getFreeHeap() / 1024;
    s += "KB\n";
    otaServer.send(200, "text/plain", s);
  });
  otaServer.begin();
  Serial.printf(">>> OTA ready: curl -F firmware=@bin http://%s:%s@%s:8080/update\n",
                OTA_USER, OTA_PASS, WiFi.localIP().toString().c_str());
}

/* ================== 联网自动更新 (v46: 直接连 GitHub) ==================
   固件放在公开仓库, 板子自己下载:
     https://raw.githubusercontent.com/<用户>/<仓库>/main/version.txt   (内容=版本号数字)
     https://raw.githubusercontent.com/<用户>/<仓库>/main/AIBox.ino.bin (编译出的固件)
   板子开机连上 WiFi 后比对版本, 更新更大就下载升级并重启。
   => 只要板子接着电源 + 有网, 在哪都能升级, 完全不用电脑。
   支持: HTTPS(不校验证书) / 301·302 跳转 / chunked 传输。*/
#define GH_USER      "Semi-sugardeicing"
#define GH_REPO      "ai-voice-box"
#define GH_BRANCH    "main"

/* v48: 电脑中转(家里那台), 固件放在 %USERPROFILE%\aibox-fw\ 里
   板子先问电脑, 电脑不通再问 GitHub —— 两条路都能用。
   不想用电脑就把 PC_ENABLE 改 0。 */
#define PC_ENABLE    1
#define PC_HOST      "192.168.1.5"
#define PC_PORT      8000

/* 下载过程中的全局状态 */
String g_body;
bool   upStarted = false;
bool   upFailed  = false;
long   upGot     = 0;
unsigned long upLastDraw = 0;
int g_upTargetVer = 0;
long g_upTotal = 0;      /* 固件总字节, 0=未知 */
bool g_srcIsPC = false;  /* true=从电脑取, false=从 GitHub 取 */

/* 读掉一整段 HTTP 响应. hdr: 头(可选), cb: 正文回调(可选). 返回正文字节数, 失败 -1 */
long httpGet(const char* url, String* hdr, void (*cb)(const uint8_t*, size_t)) {
  String cur = String(url);
  for (int hop = 0; hop < 4; hop++) {
    bool secure = cur.startsWith("https://");
    int hostStart = secure ? 8 : 7;
    int slash = cur.indexOf('/', hostStart);
    if (slash < 0) return -1;
    String hostPort = cur.substring(hostStart, slash);
    String path = cur.substring(slash);
    String host = hostPort;
    int port = secure ? 443 : 80;
    int colon = hostPort.indexOf(':');
    if (colon > 0) { host = hostPort.substring(0, colon); port = hostPort.substring(colon + 1).toInt(); }

    WiFiClientSecure sc;
    WiFiClient plain;
    Client* c;
    if (secure) { sc.setInsecure(); sc.setTimeout(15000); c = &sc; }
    else        { plain.setTimeout(15000);             c = &plain; }
    if (!c->connect(host.c_str(), port)) { Serial.printf(">>> http: connect %s fail\n", host.c_str()); return -1; }

    c->printf("GET %s HTTP/1.1\r\n", path.c_str());
    c->printf("Host: %s\r\n", host.c_str());
    c->print("User-Agent: AIBox/ESP32\r\nConnection: close\r\n\r\n");

    String head = "";
    unsigned long t0 = millis();
    while (millis() - t0 < 15000) {
      if (!c->available()) { if (!c->connected()) break; delay(5); continue; }
      head += (char)c->read();
      if (head.endsWith("\r\n\r\n")) break;
      if (head.length() > 4000) break;
      t0 = millis();
    }
    if (hdr) *hdr = head;

    int code = 0;
    int sp = head.indexOf(' ');
    if (sp > 0) code = head.substring(sp + 1, sp + 4).toInt();

    if (code == 301 || code == 302 || code == 307 || code == 308) {
      int loc = head.indexOf("ocation: ");
      if (loc < 0) { c->stop(); return -1; }
      int e = head.indexOf("\r\n", loc);
      cur = head.substring(loc + 10, e);
      c->stop();
      Serial.printf(">>> http: %d -> %s\n", code, cur.c_str());
      continue;
    }
    if (code != 200) { Serial.printf(">>> http: code %d\n", code); c->stop(); return -1; }

    bool chunked = head.indexOf("chunked") > 0;
    long total = -1;
    int cl = head.indexOf("Content-Length:");
    if (cl < 0) cl = head.indexOf("content-length:");
    if (cl >= 0) { int e = head.indexOf("\r\n", cl); total = head.substring(cl + 15, e).toInt();
      if (cb && total > 0) g_upTotal = total; }

    long got = 0;
    long chunkRemain = 0;
    uint8_t buf[1024];
    unsigned long last = millis();
    while (millis() - last < 25000) {
      if (!c->available()) {
        if (!c->connected() && !c->available()) break;
        if (!chunked && total > 0 && got >= total) break;
        delay(2); continue;
      }
      int av = c->available();
      int want = av > (int)sizeof(buf) ? sizeof(buf) : av;

      if (chunked) {
        /* chunked: 当前在块边界时先读长度行 */
        if (chunkRemain == 0) {
          String line = "";
          while (c->available() && line.length() < 20) {
            char ch = c->read();
            if (ch == '\n') break;
            if (ch != '\r') line += ch;
          }
          if (line.length() == 0) { delay(2); continue; }
          chunkRemain = strtol(line.c_str(), NULL, 16);
          if (chunkRemain <= 0) break;
          continue;
        }
        if (want > chunkRemain) want = (int)chunkRemain;
      }

      int n = c->read(buf, want);
      if (n <= 0) continue;
      if (chunked) chunkRemain -= n;
      if (cb) cb(buf, n);
      got += n; last = millis();
      if (!chunked && total > 0 && got >= total) break;
    }
    c->stop();
    return got;
  }
  return -1;
}

/* ---- 版本号 ---- */
/* 从某个地址读版本号, 失败返回 -1 */
int fetchVerFrom(const char* url) {
  g_body = "";
  httpGet(url, NULL, [](const uint8_t* d, size_t n) {
    for (size_t i = 0; i < n; i++) g_body += (char)d[i];
  });
  String v = "";
  for (int i = 0; i < (int)g_body.length(); i++)
    if (g_body[i] >= '0' && g_body[i] <= '9') v += g_body[i];
  return v.length() ? v.toInt() : -1;
}

int fetchRemoteVer() {
#if PC_ENABLE
  char pcUrl[96];
  snprintf(pcUrl, sizeof(pcUrl), "http://%s:%d/version.txt", PC_HOST, PC_PORT);
  int v = fetchVerFrom(pcUrl);
  g_srcIsPC = (v > 0);
  Serial.printf(">>> PC ver=%d\n", v);
  if (v > 0) return v;
#endif
  g_srcIsPC = false;
  return fetchVerFrom("https://raw.githubusercontent.com/" GH_USER "/" GH_REPO "/" GH_BRANCH "/version.txt");
}

/* ---- 下载固件并刷写 ---- */
bool selfUpdate(int ver) {
  Serial.printf(">>> update to v%d from GitHub\n", ver);
  upStarted = false; upFailed = false; upGot = 0; upLastDraw = 0; g_upTotal = 0;
  g_upTargetVer = ver;
  if (screenOK) {
    display.clearDisplay(); display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 10); display.print("UPDATE FROM GITHUB");
    display.display();
  }
  String binUrl;
#if PC_ENABLE
  if (g_srcIsPC) {
    char u[96]; snprintf(u, sizeof(u), "http://%s:%d/AIBox.ino.bin", PC_HOST, PC_PORT);
    binUrl = u;
  } else
#endif
  { binUrl = "https://raw.githubusercontent.com/" GH_USER "/" GH_REPO "/" GH_BRANCH "/AIBox.ino.bin"; }
  Serial.printf(">>> firmware from %s\n", binUrl.c_str());
  long r = httpGet(binUrl.c_str(),
                   NULL, [](const uint8_t* d, size_t n) {
    if (!upStarted) {
      upStarted = true;
      if (!Update.begin(UPDATE_SIZE_UNKNOWN)) { upFailed = true; Update.printError(Serial); return; }
    }
    if (upFailed) return;
    if (Update.write((uint8_t*)d, n) != n) { upFailed = true; Update.printError(Serial); return; }
    upGot += n;
    if (millis() - upLastDraw > 400) {
      upLastDraw = millis();
      if (screenOK) {
        display.clearDisplay(); display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(0, 6); display.print(g_srcIsPC ? "FROM PC" : "FROM GITHUB");
        display.setCursor(80, 6); display.print("v"); display.print(g_upTargetVer);

        /* 已下载 KB */
        display.setTextSize(2);
        display.setCursor(0, 20);
        display.print(upGot / 1024);
        display.setTextSize(1);
        display.setCursor(display.getCursorX(), 26);
        display.print("K");

        /* 进度条 (总大小未知, 用已知参考 960KB 估算, 到 100% 自动满) */
        int pw = 0;
        if (g_upTotal > 0)      pw = (int)(120L * upGot / g_upTotal);
        else if (upGot > 0)     pw = (int)(120L * upGot / (980L * 1024));
        if (pw > 120) pw = 120;
        display.drawRect(0, 44, 124, 10, SSD1306_WHITE);
        if (pw > 0) display.fillRect(2, 46, pw, 6, SSD1306_WHITE);

        /* 百分比 */
        display.setCursor(0, 56);
        display.print("progress ");
        if (g_upTotal > 0) display.print((int)(100L * upGot / g_upTotal));
        else               display.print(pw * 100 / 120);
        display.print("%");
        display.display();
      }
    }
  });
  if (upStarted && !upFailed && r > 0 && Update.end(true)) {
    Serial.printf(">>> update OK (%ld bytes), rebooting\n", r);
    if (screenOK) {
      display.clearDisplay(); display.setTextSize(2);
      display.setCursor(0, 20); display.print("UPDATED!");
      display.setTextSize(1); display.setCursor(0, 44);
      display.print("v"); display.print(ver);
      display.display();
    }
    delay(1200);
    ESP.restart();
  }
  Serial.printf(">>> update FAIL got=%ld\n", r);
  if (upStarted) Update.abort();
  return false;
}

void checkFirmwareUpdate() {
  int v = fetchRemoteVer();
  Serial.printf(">>> remote ver=%d (local %d)\n", v, FW_VER);

  if (v <= FW_VER) {
    /* 已是最新(或查不到) —— 只在串口记一下, 屏幕不打扰 */
    if (screenOK && v < 0) {
      display.clearDisplay();
      display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 24); display.print("No network update");
      display.setCursor(0, 38); display.print("offline");
      display.display();
      delay(1200);
      showIdle();
    }
    return;
  }

  /* ============ v47: 发现新版本 -> 5 秒倒计时, 可按 K4 取消 ============ */
  Serial.printf(">>> new firmware v%d found, 5s to cancel with K4\n", v);
  for (int left = 5; left > 0; left--) {
    if (screenOK) {
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 8);
      display.print("NEW FIRMWARE");
      display.setTextSize(2);
      display.setCursor(0, 22);
      display.print("v"); display.print(v);
      display.setTextSize(1);
      display.setCursor(0, 46);
      display.print("updating in ");
      display.print(left);
      display.print("s");
      display.setCursor(0, 56);
      display.print("K4 = cancel");
      display.display();
    }
    /* 每秒检查 20 次, 按下 K4 立刻取消 */
    for (int k = 0; k < 20; k++) {
      if (digitalRead(BTN_TALK) == LOW) {
        Serial.println(">>> update cancelled by K4");
        if (screenOK) {
          display.clearDisplay();
          display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
          display.setCursor(0, 26); display.print("UPDATE CANCELLED");
          display.setCursor(0, 42); display.print("keep v"); display.print(FW_VER);
          display.display();
          delay(1500);
          showIdle();
        }
        return;
      }
      delay(50);
    }
  }
  selfUpdate(v);
}

/* ================== v50: 菜单手动检查更新 ==================
   fromPC=true 只问家里电脑, false 只问 GitHub。结果显屏, 有新版本就下载刷写。 */
void updateFromSource(bool fromPC) {
  screenStatus("CHECK UPDATE", fromPC ? "FROM PC" : "FROM GITHUB", "wait...");
  int v = -1;
  g_srcIsPC = fromPC;
#if PC_ENABLE
  if (fromPC) {
    char u[96];
    snprintf(u, sizeof(u), "http://%s:%d/version.txt", PC_HOST, PC_PORT);
    v = fetchVerFrom(u);
  } else
#endif
  {
    v = fetchVerFrom("https://raw.githubusercontent.com/" GH_USER "/" GH_REPO "/" GH_BRANCH "/version.txt");
  }
  Serial.printf(">>> manual update check: %s ver=%d local=%d\n", fromPC ? "PC" : "GITHUB", v, FW_VER);
  if (v < 0)        { screenStatus("UPDATE", fromPC ? "FROM PC" : "FROM GITHUB", "CANNOT CHECK"); delay(2000); showIdle(); return; }
  if (v <= FW_VER)  { screenStatus("UPDATE", fromPC ? "FROM PC" : "FROM GITHUB", "NO NEW VERSION"); delay(2000); showIdle(); return; }
  selfUpdate(v);   /* 成功会自己重启, 失败往下走 */
  screen2("UPDATE FAIL", "keep current");
  delay(1500);
  showIdle();
}

/* ================== v53: 按键自检屏 ==================
   同时按住 K1+K2 一秒以上松开 -> 显示四个键当前电平。
   松开=HIGH(1), 按下=LOW(0)。哪个键不管按不按都是 1, 就是那个键/那根线的问题;
   一直 0 说明短路到地。也显示当前引脚定义, 核对接线。 */
void showKeyDiag() {
  while (true) {
    if (screenOK) {
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.print("KEY DIAG");
      display.setCursor(90, 0);
      display.print("v");
      display.print(FW_VER);

      struct { const char* nm; int pin; } ks[4] = {
        { "K1 ^", BTN_K1 },
        { "K2 v", BTN_BRIGHT },
        { "K3 #", BTN_REPLAY },
        { "K4 *", BTN_TALK }
      };
      for (int i = 0; i < 4; i++) {
        int y = 12 + i * 10;
        int lv = digitalRead(ks[i].pin);
        display.setCursor(0, y);
        display.print(ks[i].nm);
        display.setCursor(30, y);
        display.print("G");
        display.print(ks[i].pin);
        display.setCursor(52, y);
        display.print(lv == LOW ? "DOWN" : " -- ");
        display.setCursor(88, y);
        display.print(lv);
      }
      display.setCursor(0, 56);
      display.print("hold K4 2s = exit");
      display.display();
    }
    /* 按住 K4 两秒退出 */
    if (digitalRead(BTN_TALK) == LOW) {
      unsigned long t0 = millis();
      while (digitalRead(BTN_TALK) == LOW && millis() - t0 < 2000) delay(10);
      if (millis() - t0 >= 2000) { showIdle(); return; }
    }
    otaServer.handleClient();
    delay(80);
  }
}

/* ================== v55: 配网热点 (WiFi 连不上时用) ==================
   连不上任何已知 WiFi -> 盒子自己开热点 AIBox-Setup (无密码),
   手机连上去, 浏览器打开 http://192.168.4.1 , 填 WiFi 名/密码 -> 存 NVS -> 重启。
   这样换热点/换地方再也不用改代码、不用发新版本。 */
#define AP_SSID  "AIBox-Setup"

WebServer cfgServer(80);
DNSServer dnsServer;

void drawSetupScreen() {
  if (!screenOK) return;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("WiFi SETUP");
  display.setTextSize(2);
  display.setCursor(0, 16);
  display.print("AIBox-Setup");
  display.setTextSize(1);
  display.setCursor(0, 40);
  display.print("join it, then open");
  display.setCursor(0, 52);
  display.print("192.168.4.1");
  display.display();
}

void runConfigPortal() {
  Serial.println(">>> no WiFi, starting config portal");
  WiFi.mode(WIFI_AP);
  WiFi.softAP(AP_SSID);
  Serial.print(">>> AP IP: "); Serial.println(WiFi.softAPIP());
  dnsServer.start(53, "*", WiFi.softAPIP());   /* 任何域名都跳到配置页 */

  cfgServer.on("/", HTTP_GET, []() {
    String h = "<!DOCTYPE html><html><head><meta charset='utf-8'>";
    h += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
    h += "<title>AI Box WiFi</title></head><body style='font-family:sans-serif;max-width:420px;margin:20px auto;padding:0 14px'>";
    h += "<h3>AI Box WiFi Setup</h3>";
    h += "<form method='GET' action='/save'>";
    h += "<p>WiFi name<br><input name='ssid' style='width:100%;padding:10px;font-size:16px' value='";
    h += g_wifiSsid; h += "'></p>";
    h += "<p>Password<br><input name='pass' type='password' style='width:100%;padding:10px;font-size:16px'></p>";
    h += "<button style='padding:12px 30px;font-size:16px'>CONNECT</button></form>";
    h += "<p style='color:#888;font-size:13px'>After saving the box restarts and joins your WiFi.</p>";
    h += "</body></html>";
    cfgServer.send(200, "text/html", h);
  });

  cfgServer.on("/save", HTTP_GET, []() {
    String ssid = cfgServer.arg("ssid");
    String pass = cfgServer.arg("pass");
    ssid.trim();
    if (ssid.length() == 0) {
      cfgServer.send(200, "text/html", "<h3>WiFi name is empty</h3><p><a href='/'>back</a></p>");
      return;
    }
    saveWifiCred(ssid, pass);
    cfgServer.send(200, "text/html",
      "<h3>Saved!</h3><p>Box is restarting and will join your WiFi.</p>");
    if (screenOK) {
      display.clearDisplay(); display.setTextSize(1);
      display.setCursor(0, 20); display.print("SAVED");
      display.setCursor(0, 36); display.print("rebooting...");
      display.display();
    }
    delay(1500);
    ESP.restart();
  });

  cfgServer.begin();
  drawSetupScreen();

  /* 一直停在配网模式, 直到有人填好 (填好后自动重启) */
  while (true) {
    dnsServer.processNextRequest();
    cfgServer.handleClient();
    delay(2);
  }
}

/* ================== setup ================== */
void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println();
  Serial.printf("=== AI Box v%d ===\n", FW_VER);

  loadSettings();                       /* v50: 密钥/亮度/音量/走马灯 从 NVS 读入 */
  loadWifiCred();                       /* v55: NVS 里配过网的话优先用 */

  pixels.begin();
  pixels.clear();
  pixels.show();
  setLedByPeriod(-1);

  pinMode(BTN_TALK,   INPUT_PULLUP);   /* v38: 四键全部上拉 */
  pinMode(BTN_BRIGHT, INPUT_PULLUP);
  pinMode(BTN_REPLAY, INPUT_PULLUP);
  pinMode(BTN_K1,     INPUT_PULLUP);

  /* 录音缓冲 */
  size_t bytes = sizeof(int16_t) * MAX_SAMPLES + 64;   /* 多留 44 字节放 WAV 头 */
  Serial.printf("PSRAM: %s, size=%u\n", psramFound() ? "FOUND" : "NOT FOUND",
                (unsigned)(psramFound() ? ESP.getPsramSize() : 0));
  pcmBuf = (int16_t*)(psramFound() ? ps_malloc(bytes) : malloc(bytes));
  if (!pcmBuf) {
    Serial.println("PSRAM alloc fail");
    while (1) delay(1000);
  }
  Serial.println("buffer OK");

  /* 屏幕 */
  Wire.begin(8, 9);
  Wire.setClock(400000);
  screenOK = display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.println(screenOK ? "screen OK" : "screen NOT FOUND");

  /* I2S */
  setupMicI2S();
  setupSpkI2S(sampleRate);

  /* 先校准底噪(此时喇叭静音, 测到的才是真实环境声) */
  g_baseline = calibrate();
  {
    int byRatio = (int)(g_baseline * START_RATIO);
    int t = byRatio > START_ABS ? byRatio : START_ABS;
    if (t > 4000) t = 4000;
    g_threshold = t;
  }
  Serial.printf(">>> threshold=%d\n", g_threshold);
  delay(1200);

  /* 校准完再放自检音 */
  playSelfTest();
  delay(600);

  /* WiFi */
  if (!connectWiFi()) {
    /* v55: 重试两轮仍失败 -> 开热点让手机配网 (以前是死等, 出门在外没救) */
    screen2("WiFi FAIL", "retrying...");
    for (int r = 0; r < 2 && !wifiReady; r++) {
      delay(3000);
      if (connectWiFi()) break;
    }
    if (!wifiReady) runConfigPortal();   /* 不返回, 填好会自己重启 */
  }
  screen2("WiFi OK", WiFi.localIP().toString().c_str());
  delay(600);

  startOtaServer();                   /* v39: 启动无线升级服务 */
  checkFirmwareUpdate();              /* v40: 查电脑上有没新固件, 有就自动升级 */
  fetchBalance();
  showIdle();
  Serial.println(">>> READY, speak now");
}

/* ================== 一次完整对话 ================== */
void doTurnCore();                  /* 定义在 doOneTurn 之后 */
void doOneTurn(int baseline, int threshold) {
  /* 1. 录音 */
  Serial.println(">>> recording");
  pcmLen = recordSpeech(baseline);
  Serial.printf(">>> recorded %.2f sec\n", pcmLen / (float)sampleRate);
  doTurnCore();
}

/* v34 按键模式: 按住 BOOT 录音, 松开返回 */
long recordWhileHeld() {
  long len = 0;
  memset(pcmBuf, 0, 64);
  unsigned long lastScreen = 0;
  while (digitalRead(BTN_TALK) == LOW && len < MAX_SAMPLES) {
    int got = 0;
    int e = readBlockEx(pcmBuf + 22 + len, (int)(MAX_SAMPLES - len), &got);
    if (got > 0) len += got;
    if (millis() - lastScreen > 120) {
      lastScreen = millis();
      if (screenOK) {
        display.clearDisplay();
        display.setTextColor(SSD1306_WHITE);
        drawTopBar();
        display.setTextSize(1);
        display.setCursor(0, 12);
        display.print("REC ");
        display.print(len / (float)sampleRate, 1);
        display.print(" s");
        display.setTextSize(2);
        display.setCursor(0, 24);
        display.print(">>>");
        long barLen = (e > 0 ? e : 0) / 30;
        if (barLen > 120) barLen = 120;
        display.drawRect(0, 52, 120, 8, SSD1306_WHITE);
        display.fillRect(0, 52, barLen, 8, SSD1306_WHITE);
        display.display();
      }
    }
  }
  return len;
}

/* ================== 屏幕亮度 (v36) ==================
   SSD1306 没有背光, 亮度 = 对比度命令。三档循环: 最亮/次亮/熄屏。
   熄屏时按 K1 会先点亮屏幕再说话。*/
/* ============ v42 夜间模式 ============
   睡觉时段(默认 23 点到 7 点): 走马灯(LED)关闭 + 屏幕自动变暗。
   时间来自 NTP, 没同步好就当白天处理。*/
#define NIGHT_START_HOUR 22
#define NIGHT_END_HOUR   7

bool isNightTime() {
  if (!timeReady) return false;
  time_t now = time(nullptr);
  struct tm ti;
  localtime_r(&now, &ti);
  int h = ti.tm_hour;
  return (h >= NIGHT_START_HOUR || h < NIGHT_END_HOUR);
}

/* 返回 "23:45" (只要时分, 不要秒) */
const char* getTimeHM() {
  static char t[8];
  if (!timeReady) { strcpy(t, "--:--"); return t; }
  time_t now = time(nullptr);
  struct tm ti;
  localtime_r(&now, &ti);
  snprintf(t, sizeof(t), "%02d:%02d", ti.tm_hour, ti.tm_min);
  return t;
}

/* 屏幕亮度: 2=最亮 1=次亮 0=熄屏; 夜里(最亮档)自动降到暗 */
void applyBrightness() {
  uint8_t c;
  if (g_bright == 0)      c = 0x00;                 /* 熄屏 */
  else if (g_bright == 1) c = 0x35;                 /* 次亮 */
  else                    c = isNightTime() ? 0x20 : 0xCF;   /* 最亮, 夜里自动变暗 */
  /* 直接发 I2C 命令给 0x3C (SSD1306): 0x00=命令流, 0x81=SETCONTRAST */
  Wire.beginTransmission(0x3C);
  Wire.write((uint8_t)0x00);
  Wire.write((uint8_t)0x81);
  Wire.write(c);
  Wire.endTransmission();
}

/* 单键模式: 任意一个键按下都算 */
bool anyKeyDown() {
  return digitalRead(BTN_TALK) == LOW || digitalRead(BTN_BRIGHT) == LOW ||
         digitalRead(BTN_REPLAY) == LOW || digitalRead(BTN_K1) == LOW;
}

/* v35: 重播上一句 —— v50 起由 K3 菜单里选, 见 menuEnterShort() */
void replayLast() {
  if (!g_lastAudio || g_lastSamples <= 0) {
    screen2("NO REPLAY", "nothing yet");
    delay(700);
    return;
  }
  screen2("REPLAY", "last answer");
  playPCM((int16_t*)(g_lastAudio + g_lastOff), g_lastSamples, g_lastRate);
  showIdle();
}

/* ================== v50: K3 菜单系统 ==================
   按键: K1∧ 上 / K2∨ 下(调值时=加减) / K3# 短按=进入·确认,
        长按 K3(>0.8秒)=退出菜单, 12 秒无操作自动退出并保存。
   菜单项: BRIGHT 屏幕亮度 / VOLUME 喇叭音量 / LED 走马灯 /
           REPLAY 重播 / UPDATE 检查更新(从电脑或 GitHub)。 */
#define MENU_ITEMS 5
static bool k1Was = false, k2Was = false, k3Was = false;
static unsigned long k3DownMs = 0;
static bool k3Fired = false;

const char* menuName(int i) {
  switch (i) {
    case 0:  return "BRIGHT";
    case 1:  return "VOLUME";
    case 2:  return "LED";
    case 3:  return "REPLAY";
    default: return "UPDATE";
  }
}

void menuValue(char* buf, int i) {
  switch (i) {
    case 0: strcpy(buf, g_bright == 2 ? "HIGH" : g_bright == 1 ? "MID" : "OFF"); break;
    case 1: sprintf(buf, "%d%%", (g_volIdx + 1) * 20); break;
    case 2: strcpy(buf, g_ledMode == 0 ? "AUTO" : g_ledMode == 1 ? "RED" :
                       g_ledMode == 2 ? "GREEN" : "OFF"); break;
    default: strcpy(buf, ">");
  }
}

/* ================== v54: 菜单 (白底黑字反色高亮) ==================
   按键: K1∧ 上一个 / K2∨ 下一个 / K3# 确定 / 长按 K3 退出
   设置项改成"焦点在选项上": 每一屏都有若干选项, 选中的那个白底黑字。 */

int g_menuSel = 0;   /* 当前设置项里光标指向的选项下标 (按 K3 才生效) */

/* ============ v54 中文菜单点阵字库 (16x16, 文泉驿正黑提取) ============
   34 个字, 共 1088 字节。bit15=最左像素。 */
static const uint16_t ZH_MENU_FONT[][16] = {
  { 0x0000, 0x0000, 0x0000, 0x0C20, 0x7FFE, 0x0C20, 0x0020, 0x3FF8, 0x0208, 0x3388, 0x18B0, 0x0980, 0x7FFE, 0x03C0, 0x07A0, 0x1D98 }, /* 菜 */
  { 0x0000, 0x0000, 0x0000, 0x0820, 0x0C20, 0x0660, 0x1FF8, 0x1108, 0x1188, 0x1FF8, 0x1108, 0x1FF8, 0x1108, 0x0180, 0x7FFE, 0x0100 }, /* 单 */
  { 0x0000, 0x0000, 0x0000, 0x0300, 0x7FFE, 0x0000, 0x0FF0, 0x0810, 0x0FF0, 0x0000, 0x7FFE, 0x4002, 0x47E2, 0x0420, 0x0C22, 0x0822 }, /* 亮 */
  { 0x0000, 0x0000, 0x0000, 0x0080, 0x1FFE, 0x3210, 0x3310, 0x3FFE, 0x3210, 0x33F0, 0x3000, 0x37F8, 0x3318, 0x3110, 0x20E0, 0x20E0 }, /* 度 */
  { 0x0000, 0x0000, 0x0000, 0x0300, 0x3FF8, 0x0830, 0x0820, 0x0C60, 0xFFFE, 0x0000, 0x0000, 0x1FF0, 0x1010, 0x1FF0, 0x1010, 0x1010 }, /* 音 */
  { 0x0000, 0x0000, 0x0000, 0x1FF0, 0x1018, 0x1FF8, 0x1018, 0x0000, 0xFFFE, 0x1FF0, 0x1118, 0x1FF8, 0x1108, 0x1FF0, 0x0180, 0x0100 }, /* 量 */
  { 0x0000, 0x0000, 0x0000, 0x0180, 0x0100, 0x0180, 0x1FF8, 0x0100, 0x0100, 0x7FFC, 0x0100, 0x1900, 0x1988, 0x19F8, 0x1D00, 0x1700 }, /* 走 */
  { 0x0000, 0x0000, 0x0000, 0x0000, 0x3FF0, 0x0030, 0x0830, 0x0820, 0x0820, 0x1820, 0x1FFC, 0x0FFC, 0x0004, 0x7FE4, 0x0004, 0x0004 }, /* 马 */
  { 0x0000, 0x0000, 0x0000, 0x1800, 0x1800, 0x19FE, 0x1A10, 0x5E10, 0x5C10, 0x5810, 0xD810, 0x1810, 0x1810, 0x1C10, 0x3610, 0x2010 }, /* 灯 */
  { 0x0000, 0x0000, 0x0000, 0x3FF8, 0x3180, 0x0180, 0x7FFE, 0x0180, 0x3188, 0x1188, 0x1FF8, 0x1188, 0x1FF8, 0x0100, 0x3FFC, 0x0100 }, /* 重 */
  { 0x0000, 0x0000, 0x0000, 0x103C, 0x33E0, 0x1348, 0x3158, 0x79F0, 0x10F0, 0x11F0, 0x3B4C, 0xF7FE, 0x1264, 0x136C, 0x136C, 0x1264 }, /* 播 */
  { 0x0000, 0x0000, 0x0000, 0x1860, 0x1860, 0x18D0, 0x1898, 0x7F8E, 0x1B02, 0x3EF8, 0x3C40, 0x7964, 0x592C, 0xD9A8, 0x1898, 0x1810 }, /* 检 */
  { 0x0000, 0x0000, 0x0000, 0x0180, 0x0180, 0x7FFE, 0x07E0, 0x1D38, 0x710C, 0x4180, 0x1810, 0x1810, 0x0FF0, 0x1810, 0x1FF0, 0x0000 }, /* 查 */
  { 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFE, 0x0100, 0x1FF8, 0x3188, 0x3108, 0x1FF8, 0x3108, 0x3FF8, 0x0180, 0x0900, 0x0700, 0x0700 }, /* 更 */
  { 0x0000, 0x0000, 0x0000, 0x0800, 0x7F7C, 0x2260, 0x3260, 0x1E60, 0x7FFE, 0x0C6C, 0x0C6C, 0x7FEC, 0x1E4C, 0x3F4C, 0x2D4C, 0x6CCC }, /* 新 */
  { 0x0000, 0x0000, 0x0000, 0x0820, 0x0C60, 0x06C0, 0x3FFC, 0x0100, 0x0100, 0x0100, 0x3FFE, 0x03C0, 0x01C0, 0x0240, 0x0620, 0x0C10 }, /* 关 */
  { 0x0000, 0x0000, 0x0000, 0x1000, 0x1BFC, 0x4886, 0x4086, 0x4FF6, 0x4186, 0x4386, 0x4286, 0x4686, 0x4C86, 0x5086, 0x4086, 0x4186 }, /* 闭 */
  { 0x0000, 0x0000, 0x0000, 0x1000, 0x10FE, 0x10FE, 0xFE10, 0x1010, 0x1010, 0x1E10, 0x7810, 0xD010, 0x1010, 0x1010, 0x1010, 0x1010 }, /* 打 */
  { 0x0000, 0x0000, 0x0000, 0x0000, 0x3FFC, 0x0420, 0x0420, 0x0420, 0x0420, 0x7FFE, 0x7FFE, 0x0420, 0x0420, 0x0420, 0x0C20, 0x1820 }, /* 开 */
  { 0x0000, 0x0000, 0x0000, 0x0100, 0x0300, 0x0600, 0x3FF8, 0x2008, 0x2008, 0x3FF8, 0x2008, 0x2008, 0x3FF8, 0x3008, 0x2008, 0x3008 }, /* 自 */
  { 0x0000, 0x0000, 0x0000, 0x0020, 0x0020, 0x3E20, 0x0020, 0x00FE, 0xFF26, 0x1826, 0x1026, 0x3626, 0x2226, 0x7F66, 0x6046, 0x00C6 }, /* 动 */
  { 0x0000, 0x0000, 0x0000, 0x0800, 0x1800, 0x31FC, 0x2420, 0x6C20, 0xFC20, 0x1820, 0x3020, 0x6020, 0x7C20, 0x0020, 0x0620, 0x7820 }, /* 红 */
  { 0x0000, 0x0000, 0x0000, 0x0000, 0x21F8, 0x2008, 0x49F8, 0x5808, 0xF008, 0x23FE, 0x2244, 0x434C, 0xE060, 0x00F0, 0x0F78, 0x644E }, /* 绿 */
  { 0x0000, 0x0000, 0x0000, 0x0300, 0x7FFE, 0x0000, 0x0FF0, 0x0830, 0x0FF0, 0x0000, 0x3FFC, 0x6004, 0x67E4, 0x6C24, 0x6C24, 0x6FE4 }, /* 高 */
  { 0x0000, 0x0000, 0x0000, 0x0100, 0x0100, 0x0100, 0x7FFC, 0x4104, 0x4104, 0x4104, 0x4104, 0x7FFC, 0x4104, 0x0100, 0x0100, 0x0100 }, /* 中 */
  { 0x0000, 0x0000, 0x0000, 0x1000, 0x1BFC, 0x4806, 0x4006, 0x47E6, 0x4426, 0x4426, 0x47E6, 0x4426, 0x4426, 0x47E6, 0x4466, 0x4006 }, /* 间 */
  { 0x0000, 0x0000, 0x0000, 0x0040, 0x7E40, 0x10F8, 0x1098, 0x3198, 0x21B6, 0x7D92, 0x75FE, 0x7592, 0xF5B2, 0x3592, 0x3592, 0x3D12 }, /* 确 */
  { 0x0000, 0x0000, 0x0000, 0x0300, 0x0180, 0x7FFC, 0x4004, 0x4004, 0x3FFC, 0x0180, 0x0180, 0x1980, 0x19F8, 0x1980, 0x3980, 0x2580 }, /* 定 */
  { 0x0000, 0x0000, 0x0000, 0x2060, 0x2160, 0x13FE, 0x0260, 0x0660, 0x0460, 0xF3FE, 0x10B0, 0x10B0, 0x11B3, 0x1112, 0x171E, 0x1C00 }, /* 选 */
  { 0x0000, 0x0000, 0x0000, 0x1000, 0x11FC, 0x1088, 0x18D8, 0x7C70, 0x1070, 0x11BE, 0x1F20, 0x71FC, 0x1020, 0x1020, 0x17FE, 0x1020 }, /* 择 */
  { 0x0000, 0x0000, 0x0000, 0x63F8, 0x3208, 0x0318, 0x0308, 0x7208, 0x13F8, 0x1204, 0x13D8, 0x1270, 0x1330, 0x13D8, 0x1384, 0x3C00 }, /* 退 */
  { 0x0000, 0x0000, 0x0000, 0x0100, 0x0100, 0x2108, 0x2108, 0x2108, 0x2108, 0x3FF8, 0x0100, 0x4108, 0x410C, 0x410C, 0x410C, 0x7FFC }, /* 出 */
  { 0x0000, 0x0000, 0x0000, 0x0180, 0x0100, 0x0100, 0x0100, 0x0100, 0x0180, 0x01FC, 0x0100, 0x0100, 0x0100, 0x0100, 0x0100, 0x0180 }, /* 上 */
  { 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFE, 0x0100, 0x0100, 0x0100, 0x01C0, 0x0160, 0x0138, 0x0108, 0x0100, 0x0100, 0x0100, 0x0100 }  /* 下 */
};
static const struct { uint8_t b[3]; uint8_t idx; } ZH_MENU_MAP[] = {
  { {0xE8, 0x8F, 0x9C}, 0 }, /* 菜 */
  { {0xE5, 0x8D, 0x95}, 1 }, /* 单 */
  { {0xE4, 0xBA, 0xAE}, 2 }, /* 亮 */
  { {0xE5, 0xBA, 0xA6}, 3 }, /* 度 */
  { {0xE9, 0x9F, 0xB3}, 4 }, /* 音 */
  { {0xE9, 0x87, 0x8F}, 5 }, /* 量 */
  { {0xE8, 0xB5, 0xB0}, 6 }, /* 走 */
  { {0xE9, 0xA9, 0xAC}, 7 }, /* 马 */
  { {0xE7, 0x81, 0xAF}, 8 }, /* 灯 */
  { {0xE9, 0x87, 0x8D}, 9 }, /* 重 */
  { {0xE6, 0x92, 0xAD}, 10 }, /* 播 */
  { {0xE6, 0xA3, 0x80}, 11 }, /* 检 */
  { {0xE6, 0x9F, 0xA5}, 12 }, /* 查 */
  { {0xE6, 0x9B, 0xB4}, 13 }, /* 更 */
  { {0xE6, 0x96, 0xB0}, 14 }, /* 新 */
  { {0xE5, 0x85, 0xB3}, 15 }, /* 关 */
  { {0xE9, 0x97, 0xAD}, 16 }, /* 闭 */
  { {0xE6, 0x89, 0x93}, 17 }, /* 打 */
  { {0xE5, 0xBC, 0x80}, 18 }, /* 开 */
  { {0xE8, 0x87, 0xAA}, 19 }, /* 自 */
  { {0xE5, 0x8A, 0xA8}, 20 }, /* 动 */
  { {0xE7, 0xBA, 0xA2}, 21 }, /* 红 */
  { {0xE7, 0xBB, 0xBF}, 22 }, /* 绿 */
  { {0xE9, 0xAB, 0x98}, 23 }, /* 高 */
  { {0xE4, 0xB8, 0xAD}, 24 }, /* 中 */
  { {0xE9, 0x97, 0xB4}, 25 }, /* 间 */
  { {0xE7, 0xA1, 0xAE}, 26 }, /* 确 */
  { {0xE5, 0xAE, 0x9A}, 27 }, /* 定 */
  { {0xE9, 0x80, 0x89}, 28 }, /* 选 */
  { {0xE6, 0x8B, 0xA9}, 29 }, /* 择 */
  { {0xE9, 0x80, 0x80}, 30 }, /* 退 */
  { {0xE5, 0x87, 0xBA}, 31 }, /* 出 */
  { {0xE4, 0xB8, 0x8A}, 32 }, /* 上 */
  { {0xE4, 0xB8, 0x8B}, 33 }  /* 下 */
};
#define ZH_MENU_N 34


/* 查 UTF-8 三字节 -> 汉字下标, 找不到返回 -1 */
int zhMenuIndex(const uint8_t* p) {
  for (int i = 0; i < ZH_MENU_N; i++)
    if (p[0] == ZH_MENU_MAP[i].b[0] && p[1] == ZH_MENU_MAP[i].b[1] && p[2] == ZH_MENU_MAP[i].b[2])
      return ZH_MENU_MAP[i].idx;
  return -1;
}

/* 画一个 16x16 汉字; fg/bg 决定正色还是反色 */
void drawZh16(int idx, int x, int y, bool invert) {
  if (idx < 0) return;
  for (int r = 0; r < 16; r++) {
    uint16_t row = ZH_MENU_FONT[idx][r];
    for (int c = 0; c < 16; c++) {
      bool on = (row >> (15 - c)) & 1;
      display.drawPixel(x + c, y + r, (on != invert) ? SSD1306_WHITE : SSD1306_BLACK);
    }
  }
}

/* 画一串汉字(UTF-8), 反色时先铺白底; 返回占用宽度 */
int drawZhText(const char* s, int x, int y, bool invert) {
  int n = 0;
  for (const char* p = s; *p; p += 3) n++;
  if (invert) display.fillRect(x - 1, y - 1, n * 16 + 2, 18, SSD1306_WHITE);
  int cx = x;
  for (const char* p = s; *p; p += 3) {
    drawZh16(zhMenuIndex((const uint8_t*)p), cx, y, invert);
    cx += 16;
  }
  return n * 16;
}

/* 高亮画一格: sel=true 用白底黑字 (反色) */
void drawItem(const char* txt, int x, int y, int w, bool sel) {
  if (sel) {
    display.fillRect(x, y - 1, w, 11, SSD1306_WHITE);   /* 白底 */
    display.setTextColor(SSD1306_BLACK);                /* 黑字 */
  } else {
    display.setTextColor(SSD1306_WHITE);
  }
  display.setCursor(x, y);
  display.print(txt);
  display.setTextColor(SSD1306_WHITE);
}

/* 菜单项的中文名 (UTF-8) */
const char* menuNameCn(int i) {
  switch (i) {
    case 0:  return "亮度";
    case 1:  return "音量";
    case 2:  return "走马灯";
    case 3:  return "重播";
    default: return "检查更新";
  }
}

void drawMenu() {
  if (!screenOK) return;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  if (menuActive == 1) {
    /* 主菜单: 标题 + 5 项, 光标项白底黑字
       左侧中文名(16x16), 右侧英文值(小字) */
    /* 主菜单: 5 项, 每项 11px 高, 简化名用英文(16x16 中文放不下 5 项) */
    display.setCursor(0, 0);
    display.print("MENU");
    display.setCursor(94, 0);
    display.print("#=exit");
    for (int i = 0; i < MENU_ITEMS; i++) {
      int y = 11 + i * 10;
      bool sel = (menuCursor == i);
      char v[12];
      menuValue(v, i);
      char line[24];
      snprintf(line, sizeof(line), "%s", menuName(i));
      if (sel) display.fillRect(0, y - 1, 128, 10, SSD1306_WHITE);
      display.setTextColor(sel ? SSD1306_BLACK : SSD1306_WHITE);
      display.setCursor(2, y);
      display.print(line);
      display.setCursor(76, y);
      display.print(v);
    }
    display.setTextColor(SSD1306_WHITE);
  }
  else if (menuActive == 2) {
    /* 设置项: 中文标题 + 选项 */
    drawZhText(menuNameCn(menuCursor), 2, 0, false);
    display.setCursor(0, 56);
    display.print("K1/K2 sel K3 ok");

    const char* opts[5];
    int n = 0;
    if (menuCursor == 0) {                       /* 屏幕亮度 */
      opts[0] = "HIGH"; opts[1] = "MID"; opts[2] = "OFF"; n = 3;
    } else if (menuCursor == 1) {                /* 喇叭音量 */
      static char vb[5][6];
      for (int i = 0; i < 5; i++) { snprintf(vb[i], 6, "%d%%", (i + 1) * 20); opts[i] = vb[i]; }
      n = 5;
    } else if (menuCursor == 2) {                /* 走马灯 */
      opts[0] = "AUTO"; opts[1] = "RED"; opts[2] = "GREEN"; opts[3] = "OFF"; n = 4;
    } else {                                     /* 重播/更新: 只有一个 OK */
      opts[0] = "OK"; n = 1;
    }
    int cur = g_menuSel;
    if (cur >= n) cur = 0;
    /* n=5: 从 y=16 起, 行距 9 -> 5行到 52; n<=4 行距 11 更宽松 */
    int step = (n >= 5) ? 9 : 11;
    int y0 = 16;
    for (int i = 0; i < n; i++) {
      drawItem(opts[i], 8, y0 + i * step, 112, (cur == i));
    }
  }
  else if (menuActive == 3) {
    /* 更新源 */
    drawZhText("检查更新", 2, 0, false);
    drawItem("PC (LAN)", 8, 20, 112, menuSub == 0);
    drawItem("GITHUB",   8, 34, 112, menuSub == 1);
    display.setCursor(0, 56);
    display.print("K1/K2 sel K3 ok");
  }
  display.display();
}

/* 当前设置项有几个选项 */
int menuOptionCount(int item) {
  if (item == 0) return 3;      /* HIGH/MID/OFF */
  if (item == 1) return 5;      /* 20..100% */
  if (item == 2) return 4;      /* AUTO/RED/GREEN/OFF */
  return 1;                     /* REPLAY / UPDATE: OK */
}

/* 当前设置项的光标位置(=已保存的值) */
int menuCurrentOpt() {
  if (menuCursor == 0) return g_bright;
  if (menuCursor == 1) return g_volIdx;
  if (menuCursor == 2) return g_ledMode;
  return 0;
}

/* 光标移动一格 (只是选中, 还不生效; 按 K3 才生效) */
void menuMove(int dir) {
  int n = menuOptionCount(menuCursor);
  g_menuSel = (g_menuSel + dir + n) % n;
}

/* K3 确认: 把光标位置写进设置并立即生效 */
void menuApply() {
  if (menuCursor == 0) {
    g_bright = g_menuSel;
    applyBrightness();
  } else if (menuCursor == 1) {
    g_volIdx = g_menuSel;
    g_gain = 0.2f * (g_volIdx + 1);
  } else if (menuCursor == 2) {
    g_ledMode = g_menuSel;
    updatePeriodLed();
  }
  saveSettings();
}

void menuExit() {
  saveSettings();
  menuActive = 0;
  showIdle();
  Serial.println(">>> menu exit, saved");
}

void updateFromSource(bool fromPC);   /* 定义在后面(checkFirmwareUpdate 之后) */

void menuEnterShort() {
  menuLastMs = millis();
  if (menuActive == 1) {
    if (menuCursor == 3) {          /* REPLAY: 执行动作, 留在菜单 */
      replayLast();
      drawMenu();
    } else if (menuCursor == 4) {   /* UPDATE: 进更新源选择 */
      menuActive = 3;
      menuSub = 0;
      drawMenu();
    } else {                        /* 其余: 进设置项, 光标停在当前值 */
      g_menuSel = menuCurrentOpt();
      menuActive = 2;
      drawMenu();
    }
  } else if (menuActive == 2) {     /* K3 确定: 生效 + 存 NVS -> 回主菜单 */
    menuApply();
    menuActive = 1;
    drawMenu();
  } else if (menuActive == 3) {     /* 选更新源 -> 执行 */
    bool pc = (menuSub == 0);
    menuActive = 0;
    updateFromSource(pc);
  }
}

void menuTick() {
  /* K1 = 上 / 减 */
  bool k1 = digitalRead(BTN_K1) == LOW;
  if (k1 && !k1Was) {
    delay(30);
    if (digitalRead(BTN_K1) == LOW) {
      menuLastMs = millis();
      if (menuActive == 1)      { menuCursor = (menuCursor + MENU_ITEMS - 1) % MENU_ITEMS; drawMenu(); }
      else if (menuActive == 2) { menuMove(-1); drawMenu(); }
      else if (menuActive == 3) { menuSub = 0; drawMenu(); }
    }
  }
  k1Was = k1;

  /* K2 = 下 / 加 */
  bool k2 = digitalRead(BTN_BRIGHT) == LOW;
  if (k2 && !k2Was) {
    delay(30);
    if (digitalRead(BTN_BRIGHT) == LOW) {
      menuLastMs = millis();
      if (menuActive == 1)      { menuCursor = (menuCursor + 1) % MENU_ITEMS; drawMenu(); }
      else if (menuActive == 2) { menuMove(1); drawMenu(); }
      else if (menuActive == 3) { menuSub = 1; drawMenu(); }
    }
  }
  k2Was = k2;

  /* K3: 短按=进入/确认, 长按=退出 */
  bool k3 = digitalRead(BTN_REPLAY) == LOW;
  if (k3 && !k3Was) { k3DownMs = millis(); k3Fired = false; }
  if (k3 && !k3Fired && millis() - k3DownMs > 800) { k3Fired = true; menuExit(); }
  if (!k3 && k3Was && !k3Fired && millis() - k3DownMs < 400) menuEnterShort();
  k3Was = k3;

  /* 12 秒无操作自动退出并保存 */
  if (millis() - menuLastMs > 12000) menuExit();
}

void doButtonTurn() {
  Serial.println(">>> recording (btn, hold to talk)");
  pcmLen = recordWhileHeld();
  Serial.printf(">>> recorded %.2f sec\n", pcmLen / (float)sampleRate);
  doTurnCore();
}

void doTurnCore() {
  /* v50: 没设密钥直接提示怎么设, 不打服务器 */
  if (g_key.length() < 20) {
    String u = "http://" + WiFi.localIP().toString() + ":8080/config";
    screenStatus("NO KEY SET", u.c_str(), "open in browser");
    delay(3000);
    showIdle();
    return;
  }
  if (pcmLen < MIN_SAMPLES) {
    Serial.println(">>> too short");
    screen2("TOO SHORT", "hold & speak");
    delay(500);
    return;
  }

  /* 2. 生成 WAV */
  long wavLen = 0;
  uint8_t* wav = buildWav(pcmBuf, pcmLen, &wavLen);
  if (!wav) {
    screen2("ERROR", "no memory");
    delay(1000);
    return;
  }

  /* 3. 识别 */
  g_waitSub = "recognizing";
  drawWaiting(g_waitSub);
  Serial.println(">>> ASR");
  String resp = asrRequest(wav, wavLen);
  /* 注意: 这里绝对不能 free(wav), 因为 wav 就是 pcmBuf 本身 */
  Serial.printf(">>> ASR resp len=%d: %s\n", resp.length(), resp.substring(0, 120).c_str());

  String userText = extractJsonField(resp, "text");
  if (userText.length() == 0) {
    Serial.println(">>> ASR fail: " + resp);
    /* v43: 以前这里是个死循环(翻页显示服务器原始响应, 直到断电) ——
       按 K4 不说话就会卡死整台机器。现在改成: 显示简短提示 3 秒后回待机。 */
    if (screenOK) {
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 6);
      display.println("DIDN'T CATCH THAT");
      display.setCursor(0, 22);
      display.println("hold K4 & speak");
      display.setCursor(0, 40);
      /* 只显示第一行的简短原因, 不翻页 */
      String brief = resp.substring(0, 19);
      brief.replace("\r", " "); brief.replace("\n", " ");
      display.println(brief);
      display.display();
      delay(3000);
      showIdle();
    }
    return;
  }
  Serial.println(">>> user: " + userText);

  if (screenOK) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("YOU:");
    /* 中文显示不了, 只显示长度 */
    display.setCursor(0, 16);
    display.print("chars=");
    display.println(userText.length());
    display.display();
  }

  /* 4. 对话 */
  g_waitSub = "thinking";
  drawWaiting(g_waitSub);
  Serial.println(">>> CHAT");
  String reply = "";
  if (!chatRequest(userText, reply)) {
    screen2("CHAT FAIL", "");
    delay(1000);
    return;
  }
  Serial.println(">>> AI: " + reply);

  /* 5. 显示费用 */
  float cost = calcCost(lastPromptTok, lastCompTok);
  todayCost += cost;
  lastCost = cost;
  todayTurns++;
  Serial.printf(">>> tokens %ld/%ld, cost %.6f, sum %.6f\n",
                lastPromptTok, lastCompTok, cost, todayCost);
  showCostScreen();
  delay(1200);

  /* 6. 合成 */
  g_waitSub = "speaking";
  drawWaiting(g_waitSub);
  Serial.println(">>> TTS");
  uint8_t* audio = NULL;
  long audioLen = 0;
  if (!ttsRequest(reply, &audio, &audioLen)) {
    screen2("TTS FAIL", "");
    delay(1000);
    return;
  }

  /* 7. 播放 */
  int rate = 24000;
  long dataOff = 44;
  long samples = parseWav(audio, audioLen, &rate, &dataOff);
  Serial.printf(">>> play %ld samples @ %d Hz\n", samples, rate);

  if (samples > 0 && dataOff + samples * 2 <= audioLen) {
    drawAnswering();
    playPCM((int16_t*)(audio + dataOff), samples, rate);
  } else {
    Serial.println(">>> WAV parse fail");
  }
  /* v35: 不再立刻释放, 留着给"重播上一句"键用; 下次合成时才放掉旧的 */
  if (g_lastAudio) free(g_lastAudio);
  if (samples > 0) {
    g_lastAudio = audio;
    g_lastLen = audioLen;
    g_lastOff = dataOff;
    g_lastSamples = samples;
    g_lastRate = rate;
  } else {
    free(audio);
    g_lastAudio = NULL;
  }

  /* 上下文超过 4K 就砍掉最早的记忆 */
  if (ctxTokens > CTX_MAX && historyCount >= 2) {
    history[0] = history[2];
    history[1] = history[3];
    historyCount = 2;
    Serial.println(">>> ctx over 4K, trimmed history");
  }

  /* 8. 存记忆: 只留最近 2 轮 */
  if (historyCount >= 4) {
    history[0] = history[2];
    history[1] = history[3];
    historyCount = 2;
  }
  history[historyCount++] = userText;
  history[historyCount++] = reply;

  Serial.println(">>> turn done");
}

/* ================== loop ================== */
void loop() {
#if AUTO_LISTEN
  /* ===== 自动监听模式(旧行为): 随时说话, 音量触发 ===== */
  int baseline = g_baseline;
  int threshold = g_threshold;
  int hitCount = 0;
  unsigned long lastPrint = 0;

  while (true) {
    int c = 0;
    int e = readBlockEx(NULL, 0, &c);

    if (millis() - lastPrint > 1000) {
      lastPrint = millis();
      Serial.printf("listen e=%d need=%d hit=%d\n", e, threshold, hitCount);
    }

    if (e > threshold) hitCount++; else hitCount = 0;

    if (hitCount >= START_BLOCKS) {
      hitCount = 0;
      doOneTurn(baseline, threshold);

      /* 播放完等一会儿, 别被喇叭尾音再触发 */
      delay(600);
      fetchBalance();          /* 刷新余额(免费) */
      showIdle();
      Serial.println(">>> READY again");
    }
    delay(5);
    otaServer.handleClient();        /* v39: OTA 监听 */
  }
#else
  /* ===== 按键模式(默认) =====
     SINGLE_KEY=1: 任意键 = 按住说话 (只插一个键时用, 不管插哪个孔)
     SINGLE_KEY=0: K4 按住说话 / K2 亮度 / K3 重播 / K1 预留 */
#if SINGLE_KEY
  while (true) {
    if (anyKeyDown()) {
      delay(25);
      if (anyKeyDown()) {
        unsigned long t0 = millis();
        while (anyKeyDown() && millis() - t0 < 300) delay(5);
        if (anyKeyDown()) {
          if (g_bright == 0) { g_bright = 2; applyBrightness(); }
          doButtonTurn();
          delay(600);
          fetchBalance();
          showIdle();
          Serial.println(">>> READY again");
        } else {
          screen2("HOLD KEY TO TALK", "");
          delay(700);
          showIdle();
        }
        delay(300);
      }
    }
    otaServer.handleClient();        /* v39: OTA 监听 */
    /* v42: 每 10 分钟查一次余额; 每分钟同步夜间亮度/走马灯 */
    if (millis() - lastBalMs > 600000UL) {
      lastBalMs = millis();
      Serial.println(">>> auto balance refresh (10min)");
      fetchBalance();
      applyBrightness();
      showIdle();
    } else if (millis() - lastNightMs > 60000UL) {
      lastNightMs = millis();
      if (!timeReady && time(nullptr) > 100000) timeReady = true;
      applyBrightness();
      updatePeriodLed();
    }
    delay(10);
  }
#else
  /* ===== v50 按键分工 =====
     K4 米字 = 按住说话 (不变)
     K3 #   = 菜单: 短按进菜单, 菜单里短按=确认, 长按=退出
     K1 ∧   = 菜单里: 上移 / 调值时减小
     K2 ∨   = 菜单里: 下移 / 调值时增大   */
  while (true) {
    if (menuActive) {
      menuTick();
    }
    else if (digitalRead(BTN_TALK) == LOW) {
      delay(25);
      if (digitalRead(BTN_TALK) == LOW) {
        unsigned long t0 = millis();
        while (digitalRead(BTN_TALK) == LOW && millis() - t0 < 300) delay(5);
        if (digitalRead(BTN_TALK) == LOW) {
          if (g_bright == 0) { g_bright = 2; applyBrightness(); }  /* 熄屏时先点亮 */
          doButtonTurn();                 /* 长按: 按住说话 */
          delay(600);
          fetchBalance();
          showIdle();
          Serial.println(">>> READY again");
        } else {
          screen2("HOLD K4 TO TALK", "");  /* 短按提示 */
          delay(700);
          showIdle();
        }
        delay(300);
      }
    }
    else if (digitalRead(BTN_REPLAY) == LOW) {   /* K3: 进菜单 */
      delay(25);
      if (digitalRead(BTN_REPLAY) == LOW) {
        if (g_bright == 0) { g_bright = 2; applyBrightness(); }  /* 熄屏先点亮 */
        menuActive = 1;
        menuCursor = 0;
        menuLastMs = millis();
        drawMenu();
        Serial.println(">>> menu open");
        delay(300);
      }
    }
    /* v53: K1+K2 同时按 1 秒 = 按键自检屏 */
    else if (digitalRead(BTN_K1) == LOW && digitalRead(BTN_BRIGHT) == LOW) {
      unsigned long t0 = millis();
      while (millis() - t0 < 1000) {
        if (digitalRead(BTN_K1) != LOW || digitalRead(BTN_BRIGHT) != LOW) break;
        delay(20);
      }
      if (millis() - t0 >= 1000) {
        Serial.println(">>> key diag mode");
        while (digitalRead(BTN_K1) == LOW || digitalRead(BTN_BRIGHT) == LOW) delay(20);
        showKeyDiag();
        Serial.println(">>> key diag exit");
      }
    }
        /* v54: 菜单外 K1/K2 无反应 (她定的: 改亮度/音量/走马灯一律进 K3 菜单) */
    otaServer.handleClient();        /* v39: OTA 监听 */
    /* v42: 每 10 分钟查一次余额; 每分钟同步夜间亮度/走马灯。
       v50: 菜单开着时不刷新, 免得把菜单画面冲掉。 */
    if (!menuActive && millis() - lastBalMs > 600000UL) {
      lastBalMs = millis();
      Serial.println(">>> auto balance refresh (10min)");
      fetchBalance();
      applyBrightness();
      showIdle();
    } else if (!menuActive && millis() - lastNightMs > 60000UL) {
      lastNightMs = millis();
      if (!timeReady && time(nullptr) > 100000) timeReady = true;
      applyBrightness();
      updatePeriodLed();
    }
    delay(10);
  }
#endif
#endif
}
