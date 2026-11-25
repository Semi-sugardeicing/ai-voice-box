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
#define FW_VER 67

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
#include <esp_ota_ops.h> /* v56: 强制回滚 (切到另一个 OTA 分区里的上一版固件) */

/* ##################################################################
   ######################  只改这两处  ##############################
   ################################################################## */

/* ========== 1. DeepSeek 密钥 (v50 起): 不用写在这里! ==========
   密钥存在盒子自己的存储(NVS)里, 浏览器打开 http://盒子IP:8080/config
   输入一次即可, 以后刷任何版本固件密钥都在, 固件文件里永不含密钥。 */
String g_key = "";   /* 运行时从 NVS 读入, 见 loadSettings() */

/* ========== 2. WiFi 列表 (v56: 只写手机热点) ==========
   格式:  { "WiFi名字", "WiFi密码" },
   可以写任意多个, 自动连能连上的那个。                       */
struct WiFiItem { const char* ssid; const char* pass; };
/* v56: 只预置手机热点 (出门在外靠它自己更新)。
   家里 WiFi 故意不写进固件 —— 避免公开暴露家庭网络/大致位置。
   回家连不上会自动开 esp32-S3开发版 热点, 手机填一次就永久记住(NVS)。 */
WiFiItem WIFI_LIST[] = {
  { "一加 Ace 3",  "123456ok" },     /* 手机热点 */
  /* 在这下面加新的, 照着上面格式写: */
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
int menuTop = 0;      /* v65: 主菜单滚动位置 */
int menuCursor = 0;
int menuSub = 0;
unsigned long menuLastMs = 0;

/* ================== v55: WiFi 存在 NVS 里 ==================
   配网时手机填的 WiFi 名/密码存这里, 优先级高于固件里的 WIFI_LIST。
   这样以后换热点、换地方, 不用改代码、不用发新版本。 */
/* v56: 多 WiFi 列表, 存 NVS. 最多 MAX_WIFI 条. */
#define MAX_WIFI 8
struct SavedWifi { String ssid; String pass; };
SavedWifi g_saved[MAX_WIFI];
int g_savedN = 0;

void loadWifiCred() {
  prefs.begin("aibox", true);
  int n = prefs.getInt("wifiN", 0);
  if (n < 0) n = 0;
  if (n > MAX_WIFI) n = MAX_WIFI;
  g_savedN = n;
  for (int i = 0; i < n; i++) {
    g_saved[i].ssid = prefs.getString(("s" + String(i)).c_str(), "");
    g_saved[i].pass = prefs.getString(("p" + String(i)).c_str(), "");
  }
  prefs.end();
  Serial.printf(">>> wifi in NVS: %d saved\n", g_savedN);
  for (int i = 0; i < g_savedN; i++)
    Serial.printf("      [%d] %s\n", i, g_saved[i].ssid.c_str());
}

void persistWifiList() {
  prefs.begin("aibox", false);
  prefs.putInt("wifiN", g_savedN);
  for (int i = 0; i < MAX_WIFI; i++) {
    if (i < g_savedN) {
      prefs.putString(("s" + String(i)).c_str(), g_saved[i].ssid);
      prefs.putString(("p" + String(i)).c_str(), g_saved[i].pass);
    } else {
      prefs.remove(("s" + String(i)).c_str());
      prefs.remove(("p" + String(i)).c_str());
    }
  }
  prefs.end();
  Serial.printf(">>> wifi list persisted: %d entries\n", g_savedN);
}

/* 加一条(已存在则更新密码), 返回 true=新增 */
bool addWifi(const String& ssid, const String& pass) {
  if (ssid.length() == 0) return false;
  for (int i = 0; i < g_savedN; i++) {
    if (g_saved[i].ssid == ssid) { g_saved[i].pass = pass; persistWifiList(); return false; }
  }
  if (g_savedN >= MAX_WIFI) return false;
  g_saved[g_savedN].ssid = ssid;
  g_saved[g_savedN].pass = pass;
  g_savedN++;
  persistWifiList();
  return true;
}

/* 删第 idx 条 */
void removeWifi(int idx) {
  if (idx < 0 || idx >= g_savedN) return;
  for (int i = idx; i < g_savedN - 1; i++) g_saved[i] = g_saved[i + 1];
  g_savedN--;
  persistWifiList();
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

/* v60: SSID 改纯英文 (中文 SSID 有些手机搜不到/乱码);
   密码必须 >= 8 位 —— v59 用的 "123456" 只有 6 位, WPA2 不接受,
   WiFi.softAP() 会直接返回 false 把整次设置丢掉, 于是芯片保留自己
   默认的开放热点 ESP_XXXXXX —— 这就是她看到 ESP_7260D4 没密码的原因。 */
#define AP_SSID  "AIBox-Setup"
#define AP_PASS  "12345678"

/* ================== WiFi ================== */
/* v59: 开机就开热点。ESP32-S3 可以同时做 AP 和 STA,
   所以"一边开热点、一边找已知 WiFi"是可行的 —— 这正是她要的。
   连上 WiFi 之后再把热点关掉, 省电也少一个干扰源。 */
bool g_apOn = false;

int drawZhNew(const char* s, int x, int y, bool invert);   /* v61: 前置声明 */

void startSoftAp() {
  if (g_apOn) return;
  WiFi.mode(WIFI_AP_STA);            /* 关键: 两个都要, 不能只 AP */
  /* v60: 必须检查返回值。密码太短/名字太长都会让这里静默失败,
     然后芯片保留自己默认的 ESP_XXXXXX 开放热点, 表面上像"配置没生效"。 */
  bool ok = WiFi.softAP(AP_SSID, AP_PASS);
  if (!ok) {
    Serial.println(">>> softAP FAILED with password, retry open");
    ok = WiFi.softAP(AP_SSID);       /* 退化成开放热点, 至少名字是我们设的 */
  }
  g_apOn = ok;
  Serial.printf(">>> softAP %s: ssid=%s pass=%dchars ip=%s\n",
                ok ? "ON" : "FAIL", AP_SSID, (int)strlen(AP_PASS),
                WiFi.softAPIP().toString().c_str());
  if (screenOK) {
    display.clearDisplay();
    display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 8);  display.print("HOTSPOT:");
    display.setCursor(0, 22); display.print(AP_SSID);
    display.setCursor(0, 36); display.print("pass: ");
    display.print(AP_PASS);
    display.setCursor(0, 52); display.print(ok ? "192.168.4.1" : "AP FAILED!");
    display.display();
    delay(1200);                     /* 让她看清热点名和密码 */
  }
}

void stopSoftAp() {
  if (!g_apOn) return;
  WiFi.softAPdisconnect(true);       /* 只断 AP, 不动 STA */
  g_apOn = false;
  Serial.println(">>> softAP OFF (wifi connected)");
}

/* v61: 手动开关热点 —— K4 短按切换。
   热点默认一直开着(方便随时改配置), 不用了按一下 K4 关掉。 */
void toggleSoftAp() {
  if (g_apOn) {
    stopSoftAp();
    if (screenOK) {
      display.clearDisplay();
      drawZhNew("热点已关闭", 0, 10, false);
      display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 34); display.print("K4 = turn on again");
      display.display();
    }
  } else {
    startSoftAp();
    if (screenOK) {
      display.clearDisplay();
      drawZhNew("热点已开启", 0, 6, false);
      display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 26); display.print(AP_SSID);
      display.setCursor(0, 38); display.print("pass ");
      display.print(AP_PASS);
      display.setCursor(0, 50); display.print("192.168.4.1");
      display.display();
    }
  }
  delay(2200);
  showIdle();
}

/* v61: 把 IP 显示 sec 秒 (连上 WiFi 时用, 免得她抄不到) */
void showIpBig(int sec) {
  if (!screenOK) return;
  String ip = WiFi.localIP().toString();
  unsigned long t0 = millis();
  while (millis() - t0 < (unsigned long)sec * 1000UL) {
    display.clearDisplay();
    drawZhNew("已连上", 0, 2, false);
    /* IP 用 2 号字, 太长就拆两行 */
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    if (ip.length() <= 10) {
      display.setCursor((128 - ip.length() * 12) / 2, 22);
      display.print(ip);
    } else {
      /* 找一个靠中间的 '.' 拆行 */
      int cut = ip.indexOf('.', 5);
      if (cut < 0) cut = ip.length();
      String a = ip.substring(0, cut + 1);
      String b = ip.substring(cut + 1);
      display.setCursor((128 - a.length() * 12) / 2, 20);
      display.print(a);
      display.setCursor((128 - b.length() * 12) / 2, 40);
      display.print(b);
    }
    display.setTextSize(1);
    display.setCursor(0, 56);
    display.print(g_apOn ? "AP still on  K4=off" : "AP off  K4=on");
    display.display();
    delay(500);
  }
}

bool connectWiFi() {
  /* v56: NVS 里的多个 WiFi 全部加进去 (配网 > 固件里写死的列表) */
  for (int i = 0; i < g_savedN; i++) {
    wifiMulti.addAP(g_saved[i].ssid.c_str(), g_saved[i].pass.c_str());
  }
  int n = sizeof(WIFI_LIST) / sizeof(WIFI_LIST[0]);
  for (int i = 0; i < n; i++) {
    wifiMulti.addAP(WIFI_LIST[i].ssid, WIFI_LIST[i].pass);
  }

  Serial.print("WiFi connecting");
  screen2("WiFi...", "connecting");
  int tries = 0;
  /* v56: 等待期间也扫描按键 —— 以前这里纯 delay, 卡住时按键全没反应。
     按 K3 立刻放弃等待, 直接进配网。 */
  while (wifiMulti.run() != WL_CONNECTED && tries < 40) {
    if (digitalRead(BTN_REPLAY) == LOW) {
      delay(30);
      if (digitalRead(BTN_REPLAY) == LOW) {
        Serial.println("\n>>> K3 pressed while connecting: skip to setup");
        if (screenOK) {
          display.clearDisplay(); display.setTextSize(1);
          display.setCursor(0, 20); display.print("WiFi skipped");
          display.setCursor(0, 36); display.print("K3 -> setup");
          display.display();
        }
        delay(600);
        return false;
      }
    }
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
WebServer cfgServer(80);   /* v56: 配网门户(80端口) */

/* v56: 配对码 / 恢复码 状态 */
unsigned long g_pinEpoch = 0;
String g_pin = "";
bool   g_pinOK = false;
String g_recover = "";

/* ================== v56: 前置声明 ==================
   函数定义分散在文件各处, Arduino 自动原型有时生成不全,
   这里手工补上, 避免 "was not declared in this scope"。 */
void   handleConfigPage();
void   handleSaveKey();
void   handleAddWifi();
void   handleDelWifi();
void   handleSaveRecover();
String buildConfigHtml();
void   refreshPinIfNeeded();
int    pinRemainSec();
String recoverPretty();
bool   rollbackToOtherPartition();
void   drawRollbackConfirm();
void   runConfigPortal();

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
/* ================== v56: 配置页 (密钥 + 多 WiFi) ==================
   浏览器打开 http://192.168.4.1 (配网时) 或 http://板子IP:8080/config
   密钥打码显示, WiFi 列表可增可删。热点密码本身就是唯一凭证。 */
/* 生成配置页 HTML (密钥 + WiFi 列表). 配网门户和 OTA 页面共用。 */
String buildConfigHtml() {
  String msg = "";
  if (cfgServer.hasArg("msg")) msg = cfgServer.arg("msg");
  String html = "<!DOCTYPE html><html><head><meta charset='utf-8'>";
  html += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
  html += "<title>AI 盒子设置</title>";
  html += "<style>";
  html += "*{box-sizing:border-box}body{font-family:-apple-system,system-ui,sans-serif;";
  html += "max-width:440px;margin:0 auto;padding:16px;background:#f2f3f5;color:#1a1a1a}";
  html += "h2{margin:8px 0 4px;font-size:24px}";
  html += ".sub{color:#8a94a6;font-size:13px;margin-bottom:16px}";
  html += ".card{background:#fff;border-radius:10px;padding:16px;margin-bottom:14px}";
  html += ".ttl{font-size:16px;font-weight:600;margin-bottom:12px}";
  html += ".wifi{background:#f7f9fc;border-radius:8px;padding:10px 12px;margin-bottom:8px;";
  html += "display:flex;align-items:center;justify-content:space-between}";
  html += ".wn{font-size:14px;font-weight:500}.wp{font-size:12px;color:#aab2c0;margin-top:2px}";
  html += ".del{background:#fdeaea;color:#d64545;border:0;border-radius:6px;";
  html += "padding:8px 14px;font-size:13px;cursor:pointer}";
  html += "input{width:100%;padding:11px 12px;font-size:15px;border:0;border-radius:6px;";
  html += "background:#f5f7fa;margin-bottom:10px}";
  html += ".btn{width:100%;padding:14px;font-size:16px;border:0;border-radius:8px;";
  html += "background:#1f6feb;color:#fff;cursor:pointer;margin-bottom:8px}";
  html += ".btn2{background:#eef1f5;color:#4a5568}";
  html += ".ok{background:#e8f6ec;color:#1f7a44;padding:10px 12px;border-radius:6px;font-size:13px}";
  html += ".warn{background:#fdeaea;color:#b03a3a;padding:10px 12px;border-radius:6px;font-size:13px}";
  html += ".hint{color:#a3abb8;font-size:12px;line-height:1.7}";
  html += "</style></head><body>";

  html += "<h2>AI 盒子设置</h2>";
  html += "<div class='sub'>esp32-S3开发版 &middot; 固件 v" + String(FW_VER) + "</div>";

  if (msg == "key")   html += "<div class='ok'>密钥已保存</div><br>";
  if (msg == "wifi")  html += "<div class='ok'>WiFi 已保存，盒子正在重启</div><br>";
  if (msg == "del")   html += "<div class='ok'>已删除</div><br>";
  if (msg == "full")  html += "<div class='warn'>WiFi 列表已满(最多 8 条)</div><br>";
  if (msg == "bad")   html += "<div class='warn'>名称不能为空</div><br>";

  /* ---- 密钥卡片 ---- */
  html += "<div class='card'><div class='ttl'>DeepSeek 密钥</div>";
  if (g_key.length() >= 20) {
    html += "<div class='ok'>● 已保存</div><div style='margin-top:10px;color:#8a94a6;font-size:13px'>";
    html += g_key.substring(0, 3) + "&#8226;&#8226;&#8226;&#8226;&#8226;&#8226;&#8226;&#8226;&#8226;&#8226;&#8226;&#8226;";
    html += g_key.substring(g_key.length() - 4);
    html += "<br><span style='font-size:11px;color:#aab2c0'>(只显示首尾，中间打码)</span></div>";
  } else {
    html += "<div class='warn'>尚未设置密钥</div>";
  }
  html += "<form method='POST' action='/savekey' style='margin-top:12px'>";
  html += "<input name='key' placeholder='填入新的 sk-...' autocomplete='off'>";
  html += "<button class='btn btn2' type='submit'>只保存密钥</button></form></div>";

  /* ---- WiFi 列表 ---- */
  html += "<div class='card'><div class='ttl'>已保存的 WiFi</div>";
  if (g_savedN == 0) {
    html += "<div class='hint' style='margin-bottom:10px'>还没有保存任何 WiFi</div>";
  }
  for (int i = 0; i < g_savedN; i++) {
    html += "<div class='wifi'><div><div class='wn'>" + g_saved[i].ssid + "</div>";
    html += "<div class='wp'>&#8226;&#8226;&#8226;&#8226;&#8226;&#8226;&#8226;&#8226;</div></div>";
    html += "<form method='POST' action='/delwifi' style='margin:0'>";
    html += "<input type='hidden' name='i' value='" + String(i) + "'>";
    html += "<button class='del' onclick='return confirm(\"确定删除这个 WiFi 吗？\")'>删除</button>";
    html += "</form></div>";
  }
  html += "</div>";

  /* ---- 添加 WiFi ---- */
  html += "<div class='card'><div class='ttl'>添加 WiFi</div>";
  html += "<form method='POST' action='/addwifi'>";
  html += "<input name='ssid' placeholder='WiFi 名称' autocomplete='off'>";
  html += "<input name='pass' type='password' placeholder='密码' autocomplete='off'>";
  html += "<button class='btn' type='submit'>保存并连接</button></form></div>";

  /* 恢复码: 忘了 4 位配对码时用这个进 */
  html += "<div class='card'><div class='ttl'>恢复码</div>";
  html += "<div style='font-size:22px;letter-spacing:2px;font-weight:600;color:#1f6feb'>";
  html += recoverPretty();
  html += "</div><div class='hint' style='margin-top:8px'>忘了 4 位配对码时，在首页输入这个码即可进入。<br>";
  html += "此码用于忘记 4 位配对码时进入，改完立即生效。</div>";
  html += "<form method='POST' action='/saverecover' style='margin-top:12px'>";
  html += "<input name='r' placeholder='修改恢复码(至少4位)' autocomplete='off'>";
  html += "<button class='btn btn2' type='submit'>保存恢复码</button></form></div>";

  html += "<div class='hint'>可保存多个 WiFi，盒子会自动连能连上的那个。<br>";
  html += "密钥和各 WiFi 都存在盒子内部，刷固件不会丢。</div>";
  html += "</body></html>";

  if (WiFi.status() == WL_CONNECTED) otaServer.send(200, "text/html", html);
  else                                cfgServer.send(200, "text/html", html);
}

/* ---- 只存密钥 (不重启) ---- */
void handleSaveKey() {
  String k = otaServer.hasArg("key") ? otaServer.arg("key") : cfgServer.arg("key");
  k.trim();
  if (k.length() < 20) { otaServer.sendHeader("Location", "/?msg=bad"); otaServer.send(303); return; }
  prefs.begin("aibox", false);
  prefs.putString("key", k);
  prefs.end();
  g_key = k;
  Serial.println(">>> key saved via web");
  fetchBalance();                       /* 立刻把余额刷上屏 */
  showIdle();
  otaServer.sendHeader("Location", "/?msg=key");
  otaServer.send(303);
}

/* ---- 添加 WiFi ---- */
void handleAddWifi() {
  String ssid = otaServer.arg("ssid");
  String pass = otaServer.arg("pass");
  ssid.trim();
  if (ssid.length() == 0) { otaServer.sendHeader("Location", "/?msg=bad"); otaServer.send(303); return; }
  if (g_savedN >= MAX_WIFI) { otaServer.sendHeader("Location", "/?msg=full"); otaServer.send(303); return; }
  addWifi(ssid, pass);
  otaServer.send(200, "text/html",
    "<meta charset='utf-8'><h3>WiFi 已保存</h3><p>盒子即将重启并连接…</p>");
  if (screenOK) {
    display.clearDisplay(); display.setTextSize(1);
    display.setCursor(0, 20); display.print("SAVED");
    display.setCursor(0, 36); display.print("rebooting...");
    display.display();
  }
  delay(1500);
  ESP.restart();
}

/* ---- 删除 WiFi ---- */
void handleDelWifi() {
  int i = otaServer.arg("i").toInt();
  removeWifi(i);
  otaServer.sendHeader("Location", "/?msg=del");
  otaServer.send(303);
}

/* v56: 修改恢复码 */
void handleSaveRecover() {
  String r = otaServer.arg("r");
  r.trim();
  r.toUpperCase();
  if (r.length() >= 4) {
    prefs.begin("aibox", false);
    prefs.putString("recover", r);
    prefs.end();
    g_recover = r;
    Serial.printf(">>> recovery code changed to: %s\n", r.c_str());
  }
  otaServer.sendHeader("Location", "/?msg=key");
  otaServer.send(303);
}

/* OTA 服务上的配置页入口 (已联网时用 :8080/config 访问) */
/* ============ v62: 分块发送大页面 ============
   实测: /config 那个页面 2938 字节, 一次性 send() 只发出 1436 字节就卡住,
   客户端一直等, 主循环被拖住, 最后看门狗把板子复位 —— 这就是"网页打不开"的根因。
   改成: 先发 Content-Length 头, 再按 512 字节一段推, 每段 flush 一次。 */
void sendHtmlChunked(WebServer &srv, String &html) {
  size_t total = html.length();
  srv.setContentLength(total);
  srv.sendHeader("Cache-Control", "no-store");
  srv.send(200, "text/html", "");
  const size_t CH = 512;
  for (size_t i = 0; i < total; i += CH) {
    size_t n = total - i;
    if (n > CH) n = CH;
    srv.sendContent(html.substring(i, i + n));
    srv.client().flush();
    delay(2);                    /* 让 WiFi 任务喘口气 */
  }
}

void handleConfigPage() {
  /* v57: 配置页不再要口令 —— 同一局域网打开就能改 WiFi/密钥。
     刷固件的 /update 仍然要口令, 那才是真正需要守的动作。 */
  String html = buildConfigHtml();
  sendHtmlChunked(otaServer, html);
}

void startOtaServer() {
  otaServer.on("/update", HTTP_POST, handleOtaDone, handleOtaFile);
  otaServer.on("/config", HTTP_GET, handleConfigPage);      /* v56: 配置页(密钥+WiFi) */
  otaServer.on("/savekey", HTTP_POST, handleSaveKey);       /* v56: 只存密钥 */
  otaServer.on("/addwifi", HTTP_POST, handleAddWifi);       /* v56: 添加 WiFi */
  otaServer.on("/delwifi", HTTP_POST, handleDelWifi);       /* v56: 删除 WiFi */
  otaServer.on("/saverecover", HTTP_POST, handleSaveRecover); /* v56: 改恢复码 */
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
   连不上任何已知 WiFi -> 盒子自己开热点 esp32-S3开发版 (密码 123456),
   手机连上去, 浏览器打开 http://192.168.4.1 , 填 WiFi 名/密码 -> 存 NVS -> 重启。
   这样换热点/换地方再也不用改代码、不用发新版本。 */
/* v59: 开机默认就开这个热点, 连上 WiFi 后自动关。开着热点也能同时找 WiFi。 */


DNSServer dnsServer;

/* v56: 前置声明, drawSetupScreen 要用到配对码相关函数 */
void refreshPinIfNeeded();
int  pinRemainSec();

void drawSetupScreen() {
  if (!screenOK) return;
  refreshPinIfNeeded();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  /* 第一行: 请连 + 热点名 */
  drawZhText("请连接", 0, 0, false);
  display.setCursor(52, 4);
  display.print("esp32-S3");

  /* 第二行: 密码 123456 */
  drawZhText("密码", 0, 16, false);
  display.setCursor(36, 20);
  display.print("123456");

  /* 第三行: 打开 192.168.4.1 */
  drawZhText("打开", 0, 32, false);
  display.setCursor(36, 36);
  display.print("192.168.4.1");

  /* 底部: 配对码(白底黑字), 只放数字和秒数, 不放英文 */
  display.fillRect(0, 50, 128, 14, SSD1306_WHITE);
  display.setTextColor(SSD1306_BLACK);
  display.setTextSize(2);
  display.setCursor(2, 52);
  display.print(g_pin);
  display.setTextSize(1);
  display.setTextColor(SSD1306_BLACK);
  display.setCursor(62, 53);
  display.print(pinRemainSec());
  display.print("s");
  display.setTextColor(SSD1306_WHITE);

  display.display();
}

/* ================== v56: 4 位配对码 ==================
   板子随机生成 4 位数字, 每 60 秒换一个, 屏幕显示。
   手机进配置页要填对才能用 —— 别人连上热点也看不到你板子屏幕。
   不需要网络对时, 纯本地计数, 所以离线也能用。 */

String makePin() {
  uint32_t r = esp_random() % 10000;
  char b[8];
  snprintf(b, sizeof(b), "%04u", (unsigned)r);
  return String(b);
}

void refreshPinIfNeeded() {
  if (g_pin.length() == 0 || millis() - g_pinEpoch >= 60000UL) {
    g_pin = makePin();
    g_pinEpoch = millis();
    Serial.printf(">>> pair code: %s\n", g_pin.c_str());
  }
}

int pinRemainSec() {
  unsigned long el = millis() - g_pinEpoch;
  if (el >= 60000UL) return 60;
  return 60 - (int)(el / 1000);
}

/* ================== v56: 恢复码 ==================
   内置固定恢复码(代码里明写), 忘了 4 位配对码时用它进。
   可以在设置页修改, 改完存 NVS, 刷固件不丢。 */

#define DEFAULT_RECOVER  "AIBox888"   /* 出厂默认恢复码, 设置页可改 */

void loadRecovery() {
  prefs.begin("aibox", true);
  g_recover = prefs.getString("recover", "");
  prefs.end();
  if (g_recover.length() < 4) {
    g_recover = DEFAULT_RECOVER;
    prefs.begin("aibox", false);
    prefs.putString("recover", g_recover);
    prefs.end();
  }
  Serial.printf(">>> recovery code: %s\n", g_recover.c_str());
}

/* 显示成 ABCD-EFGH 方便抄 */
String recoverPretty() {
  if (g_recover.length() == 8) return g_recover.substring(0, 4) + "-" + g_recover.substring(4);
  return g_recover;
}


void runConfigPortal() {
  Serial.println(">>> no WiFi, starting config portal");
  /* v63: 永远用 AP+STA —— 绝不因为进配网就把上网那条掐掉 */
  WiFi.mode(WIFI_AP_STA);
  if (!WiFi.softAP(AP_SSID, AP_PASS)) {
    Serial.println(">>> portal softAP with password FAILED, retry open");
    WiFi.softAP(AP_SSID);
  }
  Serial.print(">>> AP IP: "); Serial.println(WiFi.softAPIP());
  dnsServer.start(53, "*", WiFi.softAPIP());

  /* ---- 等待输入配对码 ---- */
  cfgServer.on("/", HTTP_GET, []() {
    refreshPinIfNeeded();
    drawSetupScreen();
    if (g_pinOK) { cfgServer.sendHeader("Location", "/setup"); cfgServer.send(303); return; }

    String h = "<!DOCTYPE html><html><head><meta charset='utf-8'>";
    h += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
    h += "<title>AI 盒子</title><style>";
    h += "*{box-sizing:border-box}body{font-family:-apple-system,system-ui,sans-serif;";
    h += "max-width:420px;margin:0 auto;padding:20px;background:#f2f3f5;color:#1a1a1a}";
    h += "h2{margin:10px 0 6px;font-size:24px}.sub{color:#8a94a6;font-size:13px;margin-bottom:24px}";
    h += ".card{background:#fff;border-radius:12px;padding:20px}";
    h += ".lbl{font-size:14px;color:#5a6478;margin-bottom:12px}";
    h += "input{width:100%;padding:16px;font-size:28px;letter-spacing:12px;text-align:center;";
    h += "border:2px solid #e4e8ee;border-radius:10px;background:#fafbfc}";
    h += "button{width:100%;padding:15px;font-size:17px;border:0;border-radius:10px;";
    h += "background:#1f6feb;color:#fff;margin-top:14px}";
    h += ".warn{background:#fdeaea;color:#b03a3a;padding:10px;border-radius:6px;font-size:13px;margin-bottom:12px}";
    h += ".tip{color:#a3abb8;font-size:12px;line-height:1.7;margin-top:16px}";
    h += "</style></head><body>";
    h += "<h2>AI 盒子</h2><div class='sub'>esp32-S3开发版 &middot; 固件 v" + String(FW_VER) + "</div>";
    h += "<div class='card'>";
    if (cfgServer.hasArg("err")) h += "<div class='warn'>配对码不对，或已过期</div>";
    h += "<div class='lbl'>请输入<b>板子屏幕</b>上显示的 4 位数字<br><span style='color:#a3abb8;font-size:12px'>忘了配对码？可输入恢复码(如 AIBox888)</span></div>";
    h += "<form method='GET' action='/pin'>";
    h += "<input name='p' maxlength='10' style='letter-spacing:6px;font-size:22px' autocomplete='off' autofocus>";
    h += "<button type='submit'>进入设置</button></form>";
    h += "<div class='tip'>数字每 60 秒自动更换。<br>";
    h += "若本页打不开，请关闭手机移动数据后重试。</div>";
    h += "</div></body></html>";
    cfgServer.send(200, "text/html", h);
  });

  cfgServer.on("/pin", HTTP_GET, []() {
    refreshPinIfNeeded();
    String p = cfgServer.arg("p");
    p.trim();
    p.toUpperCase();
    p.replace("-", "");
    String want = g_recover;
    want.toUpperCase();
    if (p == g_pin || (p.length() >= 4 && p == want)) {
      g_pinOK = true;
      Serial.printf(">>> pair code OK (%s)\n", p == g_pin ? "4-digit" : "RECOVERY");
      cfgServer.sendHeader("Location", "/setup");
      cfgServer.send(303);
    } else {
      Serial.printf(">>> pair code FAIL (got %s)\n", p.c_str());
      cfgServer.sendHeader("Location", "/?err=1");
      cfgServer.send(303);
    }
  });

  /* ---- 主设置页: 密钥 + WiFi 列表 ---- */
  cfgServer.on("/setup", HTTP_GET, []() {
    if (!g_pinOK) { cfgServer.sendHeader("Location", "/"); cfgServer.send(303); return; }
    refreshPinIfNeeded();
    drawSetupScreen();
    String html = buildConfigHtml();
    sendHtmlChunked(cfgServer, html);
  });

  cfgServer.on("/savekey", HTTP_POST, []() {
    if (!g_pinOK) { cfgServer.send(403, "text/plain", "locked"); return; }
    String k = cfgServer.arg("key");
    k.trim();
    if (k.length() >= 20) {
      prefs.begin("aibox", false);
      prefs.putString("key", k);
      prefs.end();
      g_key = k;
      Serial.println(">>> key saved via portal");
    }
    cfgServer.sendHeader("Location", "/setup?msg=key");
    cfgServer.send(303);
  });

  cfgServer.on("/addwifi", HTTP_POST, []() {
    if (!g_pinOK) { cfgServer.send(403, "text/plain", "locked"); return; }
    String ssid = cfgServer.arg("ssid");
    String pass = cfgServer.arg("pass");
    ssid.trim();
    if (ssid.length() == 0) { cfgServer.sendHeader("Location", "/setup?msg=bad"); cfgServer.send(303); return; }
    if (g_savedN >= MAX_WIFI) { cfgServer.sendHeader("Location", "/setup?msg=full"); cfgServer.send(303); return; }
    addWifi(ssid, pass);
    cfgServer.send(200, "text/html",
      "<meta charset='utf-8'><body style='font-family:sans-serif;padding:24px'>"
      "<h3>WiFi 已保存</h3><p>盒子正在重启并连接…</p></body>");
    if (screenOK) {
      display.clearDisplay(); display.setTextSize(1);
      display.setCursor(0, 20); display.print("SAVED");
      display.setCursor(0, 36); display.print("rebooting...");
      display.display();
    }
    delay(1500);
    ESP.restart();
  });

  cfgServer.on("/delwifi", HTTP_POST, []() {
    if (!g_pinOK) { cfgServer.send(403, "text/plain", "locked"); return; }
    removeWifi(cfgServer.arg("i").toInt());
    cfgServer.sendHeader("Location", "/setup?msg=del");
    cfgServer.send(303);
  });

  cfgServer.on("/saverecover", HTTP_POST, []() {
    if (!g_pinOK) { cfgServer.send(403, "text/plain", "locked"); return; }
    String r = cfgServer.arg("r");
    r.trim();
    r.toUpperCase();
    if (r.length() >= 4) {
      prefs.begin("aibox", false);
      prefs.putString("recover", r);
      prefs.end();
      g_recover = r;
      Serial.printf(">>> recovery code changed: %s\n", r.c_str());
    }
    cfgServer.sendHeader("Location", "/setup?msg=key");
    cfgServer.send(303);
  });

  cfgServer.begin();
  drawSetupScreen();

  /* v56: 按住 K4 三秒 = 放弃配网, 下次开机跳过 */
  unsigned long k4t = 0;
  while (true) {
    dnsServer.processNextRequest();
    cfgServer.handleClient();

    /* 配对码到期就刷新, 并重绘屏幕 */
    static String lastPin;
    refreshPinIfNeeded();
    if (lastPin != g_pin) {
      lastPin = g_pin;
      drawSetupScreen();
    }

    if (digitalRead(BTN_TALK) == LOW) {
      if (k4t == 0) k4t = millis();
      if (millis() - k4t > 3000) {
        prefs.begin("aibox", false);
        prefs.putBool("skipsetup", true);
        prefs.end();
        if (screenOK) {
          display.clearDisplay(); display.setTextSize(1);
          display.setCursor(0, 20); display.print("SKIP SETUP");
          display.setCursor(0, 36); display.print("rebooting...");
          display.display();
        }
        delay(900);
        ESP.restart();
      }
    } else {
      k4t = 0;
    }
    delay(2);
  }
}

/* ================== v56: 强制回滚到另一份固件 ==================
   default_8MB 是双分区(ota_0 / ota_1), OTA 总是写往"当前没在跑"的那个。
   所以另一个分区里存着上一次刷进去的固件。
   直接切启动分区 + 重启, 不需要网络、不需要电脑。 */
bool rollbackToOtherPartition() {
  const esp_partition_t* running = esp_ota_get_running_partition();
  const esp_partition_t* other   = esp_ota_get_next_update_partition(NULL);
  Serial.printf(">>> running: %s\n", running ? running->label : "?");
  Serial.printf(">>> other  : %s\n", other ? other->label : "?");
  if (!other) { Serial.println(">>> rollback: no other partition"); return false; }

  esp_app_desc_t desc;
  esp_err_t e = esp_ota_get_partition_description(other, &desc);
  if (e != ESP_OK) {
    Serial.printf(">>> rollback: other partition invalid (err %d)\n", e);
    return false;
  }
  Serial.printf(">>> other holds: v%s\n", desc.version);

  if (screenOK) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 8);  display.print("ROLLBACK");
    display.setCursor(0, 24); display.print("to firmware v");
    display.print(desc.version);
    display.setCursor(0, 52); display.print("rebooting...");
    display.display();
  }
  delay(1200);

  if (esp_ota_set_boot_partition(other) != ESP_OK) {
    Serial.println(">>> rollback: set boot FAILED");
    return false;
  }
  Serial.println(">>> rollback: rebooting");
  delay(300);
  ESP.restart();
  return true;
}

/* ================== v56: 回滚确认页 ================== */
void drawRollbackConfirm() {
  if (!screenOK) return;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("ROLLBACK");

  const esp_partition_t* other = esp_ota_get_next_update_partition(NULL);
  esp_app_desc_t desc;
  display.setCursor(0, 14);
  if (other && esp_ota_get_partition_description(other, &desc) == ESP_OK) {
    display.print("to v");
    display.print(desc.version);
    display.setCursor(0, 26);
    display.print(other->label);
  } else {
    display.print("no backup!");
    display.setCursor(0, 26);
    display.print("in other slot");
  }
  display.setCursor(0, 44);
  display.print(menuSub == 0 ? ">" : " ");
  display.setCursor(8, 44);
  display.print("CANCEL");
  display.setCursor(0, 54);
  display.print(menuSub == 1 ? ">" : " ");
  display.setCursor(8, 54);
  display.print("DO IT");
  display.display();
}

/* ================== setup ================== */

/* ============ v58 前置声明 (Arduino 自动原型生成不全) ============ */
void      drawItem(const char* txt, int x, int y, int w, bool sel);
int       drawZhNew(const char* s, int x, int y, bool invert);
void      drawZhNew16(int idx, int x, int y, bool invert);
int       zhNewIndex(const uint8_t* p);
void      drawSwitchBox(const char* ver, bool hasBackup);
int       askSwitch(const char* ver, bool hasBackup);
void      doSwitchSlot();
void      toggleSoftAp();
void      showIpBig(int sec);

/* ============ v58: 切换启动分区 ============
   板子里有两个应用区(app0/app1), 各存一版。这个函数:
     1. 读出"另一个区"里那版的版本号
     2. 屏幕上显示 切换到 vXX  + OK / NO
     3. 选 OK 才切, 切完重启 */
void doSwitchSlot() {
  const esp_partition_t* running = esp_ota_get_running_partition();
  const esp_partition_t* other   = esp_ota_get_next_update_partition(NULL);
  Serial.printf(">>> running=%s  other=%s\n",
                running ? running->label : "?", other ? other->label : "?");

  char ver[16] = "";
  bool hasBackup = false;
  if (other) {
    esp_app_desc_t desc;
    if (esp_ota_get_partition_description(other, &desc) == ESP_OK) {
      /* ESP-IDF 的 version 字段会把 4 个字节按十六进制倒着拼,
         v54 会变成 "34000000" 这种, 这里还原成十进制 */
      uint32_t vnum = 0;
      for (int i = 0; i < 32 && desc.version[i]; i++) {
        char c = desc.version[i];
        int d = (c >= '0' && c <= '9') ? c - '0'
              : (c >= 'a' && c <= 'f') ? c - 'a' + 10
              : (c >= 'A' && c <= 'F') ? c - 'A' + 10 : -1;
        if (d < 0) { vnum = 0; break; }
        /* 反序: 第一位是最高位 */
        vnum = vnum * 16 + d;
      }
      if (vnum > 0 && vnum < 100000) snprintf(ver, sizeof(ver), "%u", (unsigned)vnum);
      else snprintf(ver, sizeof(ver), "%s", desc.version);
      hasBackup = true;
      Serial.printf(">>> other slot holds v%s\n", ver);
    } else {
      Serial.println(">>> other slot: no valid app");
    }
  }

  int r = askSwitch(ver, hasBackup);
  if (r != 0) {                       /* 取消或者超时 */
    Serial.println(">>> switch cancelled");
    screen2("CANCELLED", "stay here");
    delay(1200);
    showIdle();
    return;
  }

  if (screenOK) {
    display.clearDisplay();
    drawZhNew("正在重启", 0, 8, false);
    display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 30); display.print("v"); display.print(ver);
    display.setCursor(0, 46); display.print("switching slot...");
    display.display();
  }
  delay(1200);
  if (esp_ota_set_boot_partition(other) != ESP_OK) {
    Serial.println(">>> set boot partition FAILED");
    screen2("SWITCH FAILED", "stay here");
    delay(1500);
    showIdle();
    return;
  }
  Serial.println(">>> switching, rebooting");
  delay(300);
  ESP.restart();
}

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println();
  Serial.printf("=== AI Box v%d ===\n", FW_VER);

  /* v57 正式版: 启动断点只保留一行版本号, 方便一眼确认固件跑没跑起来 */

  /* v56: 开机先看有没有按住键 —— 必须放在最前面,
     因为后面校准/自检要十几秒, 那时早松手了。
       K3(#)   按住 = 强制进配网
       K1(+K4) 同时按住 = 强制回滚到另一份固件 */
  pinMode(BTN_REPLAY, INPUT_PULLUP);
  pinMode(BTN_K1,     INPUT_PULLUP);
  pinMode(BTN_TALK,   INPUT_PULLUP);
  delay(80);
  /* v57: 开机按键窗口放宽到 1.5 秒 (以前 80ms, 手慢一点就按不上) */
  unsigned long tk0 = millis();
  bool k3boot = false, k1boot = false, k4boot = false;
  while (millis() - tk0 < 1500) {
    if (digitalRead(BTN_REPLAY) == LOW) k3boot = true;
    if (digitalRead(BTN_K1)     == LOW) k1boot = true;
    if (digitalRead(BTN_TALK)   == LOW) k4boot = true;
    if (k3boot || (k1boot && k4boot)) break;   /* 已经够了, 不用等满 */
    delay(20);
  }
  bool forceSetup    = k3boot;
  bool forceRollback = (k1boot && k4boot);
  if (forceSetup)    Serial.println(">>> K3 held at boot: force config portal");
  if (forceRollback) Serial.println(">>> K1+K4 held at boot: force rollback");

  loadSettings();                       /* v50: 密钥/亮度/音量/走马灯 从 NVS 读入 */
  loadWifiCred();                       /* v55: NVS 里配过网的话优先用 */
  loadRecovery();                       /* v56: 恢复码(忘了配对码时用) */

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
  Serial.flush();

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

  /* v56: 开机时按住了 K1+K4 -> 强制回滚 (不管 WiFi/其他状态) */
  if (forceRollback) {
    while (digitalRead(BTN_K1) == LOW || digitalRead(BTN_TALK) == LOW) delay(20);
    if (!rollbackToOtherPartition()) {
      screen2("NO BACKUP", "in other slot");
      delay(2500);
    }
  }

  /* v56: 开机时按住了 K3 -> 跳过联网, 直接进配网 (不管 WiFi 是否正常) */
  if (forceSetup) {
    while (digitalRead(BTN_REPLAY) == LOW) delay(20);   /* 等松手 */
    WiFi.mode(WIFI_AP);
    runConfigPortal();               /* 不返回, 填好会自己重启 */
  }

  /* WiFi */
  /* v59: 开机先开热点, 再去连已知 WiFi (两者同时进行) */
  startSoftAp();

  if (!connectWiFi()) {
    /* v56: 上次按 K4 跳过了配网 -> 这次不再开热点, 直接离线进主循环 */
    bool skipSetup = false;
    prefs.begin("aibox", true);
    skipSetup = prefs.getBool("skipsetup", false);
    prefs.end();

    if (skipSetup) {
      Serial.println(">>> skipconfig flagged: booting offline (menu still works)");
      screen2("OFFLINE MODE", "K3 = menu");
      delay(1500);
    } else {
      screen2("WiFi FAIL", "K3=setup");
      delay(800);
      runConfigPortal();               /* 不返回, 填好会自己重启 */
    }
  }
  screen2("WiFi OK", WiFi.localIP().toString().c_str());
  delay(400);
  /* v61: 热点不再自动关 (=她要求: 改手动, 按 K4 关)。
     连上 WiFi 后屏幕上把 IP 停 10 秒, 方便抄下来；
     热点继续开着, 她随时能连回来改配置。 */
  showIpBig(10);

  startOtaServer();                   /* v39: 启动无线升级服务 */
  /* v59: 开机不再自动查 GitHub。
     救砖版绝对不能"开机就去网上下载固件覆盖自己"——
     万一网上那版是坏的, 板子会陷入 刷入→重启→卡死 的死循环, 而且每圈都在写 flash。
     要更新改用: 菜单里的"检查更新", 或者以后接 K2 长按。 */
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
#define MENU_ITEMS 6
static bool k1Was = false, k2Was = false, k3Was = false;
static unsigned long k3DownMs = 0;
static bool k3Fired = false;

const char* menuName(int i) {
  switch (i) {
    case 0:  return "BRIGHT";
    case 1:  return "VOLUME";
    case 2:  return "LED";
    case 3:  return "REPLAY";
    case 4:  return "UPDATE";
    default: return "ROLLBACK";
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
   68 个字, 共 2176 字节。bit15=最左像素。 */
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
  { 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFE, 0x0100, 0x0100, 0x0100, 0x01C0, 0x0160, 0x0138, 0x0108, 0x0100, 0x0100, 0x0100, 0x0100 }, /* 下 */
  { 0x0000, 0x0000, 0x0000, 0x0000, 0x3FFC, 0x0100, 0x0100, 0x0100, 0x7FFE, 0x0360, 0x0340, 0x0340, 0x0240, 0x0640, 0x0440, 0x1843 }, /* 无 */
  { 0x0000, 0x0000, 0x0000, 0x1050, 0x1858, 0x3048, 0x247C, 0x4DC0, 0xF840, 0x18FC, 0x3340, 0x6068, 0x7C38, 0x0030, 0x0672, 0x71DA }, /* 线 */
  { 0x0000, 0x0000, 0x0000, 0x0100, 0x7FFE, 0x4102, 0x4122, 0x3DE0, 0x2CCC, 0x659E, 0x4712, 0x1FF0, 0x7180, 0x1188, 0x1188, 0x1188 }, /* 密 */
  { 0x0000, 0x0000, 0x0000, 0x00F8, 0x7C0C, 0x30CC, 0x30CC, 0x2088, 0x3C88, 0x6488, 0x64FE, 0x6402, 0x2402, 0x27FE, 0x3C02, 0x2402 }, /* 码 */
  { 0x0000, 0x0000, 0x0000, 0x0040, 0x60C0, 0x32C2, 0x13FE, 0x0120, 0x0320, 0xF3FC, 0x3020, 0x3020, 0x37FE, 0x3020, 0x3020, 0x3020 }, /* 连 */
  { 0x0000, 0x0000, 0x0000, 0x1040, 0x1060, 0x13FC, 0x1188, 0x7890, 0x13FE, 0x1040, 0x18C0, 0xF7FE, 0x1098, 0x1190, 0x10F0, 0x1078 }, /* 接 */
  { 0x0000, 0x0000, 0x0000, 0x003C, 0x1C06, 0x1406, 0x7F06, 0x5506, 0x553E, 0x5560, 0x7760, 0x6360, 0x6160, 0x7F60, 0x4161, 0x4163 }, /* 配 */
  { 0x0000, 0x0000, 0x0000, 0x0008, 0x0008, 0x7E08, 0x2208, 0x22FE, 0x3608, 0x1488, 0x1CC8, 0x0C48, 0x1C08, 0x1608, 0x2208, 0x6008 }, /* 对 */
  { 0x0000, 0x0000, 0x0000, 0x2030, 0x31F8, 0x1118, 0x0118, 0x0118, 0xF30E, 0x37F8, 0x3198, 0x3098, 0x30D0, 0x3470, 0x3860, 0x31D8 }, /* 设 */
  { 0x0000, 0x0000, 0x0000, 0x3FFC, 0x2644, 0x3FFC, 0x0100, 0x7FFE, 0x0100, 0x1FF0, 0x1810, 0x1FF0, 0x1810, 0x1FF0, 0x1810, 0x1810 }, /* 置 */
  { 0x0000, 0x0000, 0x0000, 0x0C10, 0x7810, 0x5010, 0x109C, 0x7C94, 0x1092, 0x1893, 0x3D90, 0x3716, 0x7216, 0xD00C, 0x1008, 0x1030 }, /* 秒 */
  { 0x0000, 0x0000, 0x0000, 0x4040, 0x67FE, 0x2040, 0x23FC, 0x0040, 0x07FE, 0x7000, 0x33F8, 0x3208, 0x33F8, 0x3A08, 0x3BF8, 0x3208 }, /* 请 */
  { 0x0000, 0x0000, 0x0000, 0x2040, 0x2060, 0xF8B0, 0x6198, 0x53FE, 0x5600, 0x5380, 0x7E54, 0x13D4, 0x13D4, 0xFA54, 0x13D4, 0x1244 }, /* 输 */
  { 0x0000, 0x0000, 0x0000, 0x0600, 0x0300, 0x0080, 0x00C0, 0x01C0, 0x01C0, 0x0140, 0x0360, 0x0220, 0x0620, 0x0430, 0x0810, 0x1818 }, /* 入 */
  { 0x0000, 0x0000, 0x0000, 0x3FF8, 0x3980, 0x0180, 0x0180, 0x3FFC, 0x0180, 0x0180, 0x0180, 0xFFFE, 0x0180, 0x0180, 0x0180, 0x0180 }, /* 手 */
  { 0x0000, 0x0000, 0x0000, 0x1000, 0x10F0, 0x1090, 0x1890, 0x7C90, 0x3090, 0x3890, 0x3C90, 0x7090, 0x5190, 0xD190, 0x1112, 0x1313 }, /* 机 */
  { 0x0000, 0x0000, 0x0000, 0x3FFC, 0x0180, 0x1FF8, 0x0300, 0x0200, 0x7FFE, 0x0400, 0x0FF8, 0x1C08, 0x37F8, 0x6408, 0x07F8, 0x0408 }, /* 看 */
  { 0x0000, 0x0000, 0x0000, 0x1000, 0x11BC, 0x11C0, 0x7D00, 0x1900, 0x11FC, 0x394C, 0x3D48, 0x3548, 0x5138, 0x5130, 0xD130, 0x1278 }, /* 板 */
  { 0x0000, 0x0000, 0x0000, 0x1FF0, 0x1FF8, 0x0060, 0x00C0, 0x0180, 0x0100, 0x7FFE, 0xFFFE, 0x0100, 0x0100, 0x0100, 0x0100, 0x0100 }, /* 子 */
  { 0x0000, 0x0000, 0x0000, 0x1FFC, 0x1004, 0x1004, 0x1FFC, 0x1310, 0x11B0, 0x17FC, 0x1110, 0x1110, 0x1FFE, 0x1130, 0x3110, 0x2310 }, /* 屏 */
  { 0x0000, 0x0000, 0x0000, 0x0440, 0x7FFE, 0x0440, 0x0FF0, 0x1810, 0x1FF0, 0x1FF0, 0x0300, 0x7FFE, 0x0D30, 0x1FF8, 0x791E, 0x0930 }, /* 幕 */
  { 0x0000, 0x0000, 0x0000, 0x0800, 0x0BFC, 0x1B0C, 0x130C, 0x330C, 0x33FC, 0x7060, 0xD060, 0x17FE, 0x10F0, 0x11F0, 0x1368, 0x1666 }, /* 保 */
  { 0x0000, 0x0000, 0x0000, 0x0100, 0x0300, 0x7FFE, 0x0600, 0x0400, 0x0DFC, 0x1818, 0x1830, 0x3820, 0xDBFE, 0x1820, 0x1820, 0x1820 }, /* 存 */
  { 0x0000, 0x0000, 0x0000, 0x3BC2, 0x2EC2, 0x2E42, 0x2E5A, 0x2E5A, 0x2E5A, 0x7FFA, 0x2E5A, 0x2E5A, 0x2E5A, 0x2E5A, 0x2E42, 0x6EC2 }, /* 删 */
  { 0x0000, 0x0000, 0x0000, 0x0060, 0x7860, 0x48F0, 0x5098, 0x510E, 0x57FE, 0x5C60, 0x4820, 0x4BFE, 0x4820, 0x4928, 0x5B2C, 0x5226 }, /* 除 */
  { 0x0000, 0x0000, 0x0000, 0x2000, 0x23F8, 0x1080, 0x04C4, 0xC1A0, 0x6130, 0x0318, 0x16CE, 0x1CC2, 0x1AE8, 0x22F4, 0x24D6, 0x64D2 }, /* 添 */
  { 0x0000, 0x0000, 0x0000, 0x1800, 0x1800, 0x187C, 0x7F64, 0x1944, 0x1944, 0x1944, 0x1144, 0x1144, 0x1144, 0x3144, 0x2164, 0x217C }, /* 加 */
  { 0x0000, 0x0000, 0x0000, 0x2080, 0x2080, 0x2180, 0x37FE, 0xF920, 0xA920, 0xA3A4, 0x23AC, 0x27B8, 0x2570, 0x3C70, 0x20D0, 0x2088 }, /* 恢 */
  { 0x0000, 0x0000, 0x0000, 0x0800, 0x0FFC, 0x1800, 0x3FF0, 0x6810, 0x0FF0, 0x0810, 0x0FF0, 0x0600, 0x0FF0, 0x1A60, 0x31C0, 0x01C0 }, /* 复 */
  { 0x0000, 0x0000, 0x0000, 0x3FFC, 0x6184, 0x4104, 0x4104, 0x5FF4, 0x4104, 0x4104, 0x47E4, 0x4424, 0x4424, 0x47E4, 0x4424, 0x4004 }, /* 固 */
  { 0x0000, 0x0000, 0x0000, 0x0820, 0x0920, 0x1B20, 0x1320, 0x33FE, 0x3620, 0x7420, 0xD020, 0x17FE, 0x1020, 0x1020, 0x1020, 0x1020 }, /* 件 */
  { 0x0000, 0x0000, 0x0000, 0x0180, 0x1FFC, 0x1804, 0x1004, 0x1004, 0x1FFC, 0x1000, 0x1000, 0x13FC, 0x1206, 0x1206, 0x1206, 0x3206 }, /* 启 */
  { 0x0000, 0x0000, 0x0000, 0x0000, 0x3FF8, 0x0008, 0x0008, 0x2008, 0x2008, 0x3FF8, 0x2008, 0x2000, 0x2000, 0x2002, 0x2002, 0x2002 }, /* 已 */
  { 0x0000, 0x0000, 0x0000, 0x0300, 0x7FFC, 0x4006, 0x4006, 0x1FF0, 0x0000, 0x0000, 0x7FFE, 0x0640, 0x0440, 0x0440, 0x0442, 0x0842 }  /* 完 */
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
  { {0xE4, 0xB8, 0x8B}, 33 }, /* 下 */
  { {0xE6, 0x97, 0xA0}, 34 }, /* 无 */
  { {0xE7, 0xBA, 0xBF}, 35 }, /* 线 */
  { {0xE5, 0xAF, 0x86}, 36 }, /* 密 */
  { {0xE7, 0xA0, 0x81}, 37 }, /* 码 */
  { {0xE8, 0xBF, 0x9E}, 38 }, /* 连 */
  { {0xE6, 0x8E, 0xA5}, 39 }, /* 接 */
  { {0xE9, 0x85, 0x8D}, 40 }, /* 配 */
  { {0xE5, 0xAF, 0xB9}, 41 }, /* 对 */
  { {0xE8, 0xAE, 0xBE}, 42 }, /* 设 */
  { {0xE7, 0xBD, 0xAE}, 43 }, /* 置 */
  { {0xE7, 0xA7, 0x92}, 44 }, /* 秒 */
  { {0xE8, 0xAF, 0xB7}, 45 }, /* 请 */
  { {0xE8, 0xBE, 0x93}, 46 }, /* 输 */
  { {0xE5, 0x85, 0xA5}, 47 }, /* 入 */
  { {0xE6, 0x89, 0x8B}, 48 }, /* 手 */
  { {0xE6, 0x9C, 0xBA}, 49 }, /* 机 */
  { {0xE7, 0x9C, 0x8B}, 50 }, /* 看 */
  { {0xE6, 0x9D, 0xBF}, 51 }, /* 板 */
  { {0xE5, 0xAD, 0x90}, 52 }, /* 子 */
  { {0xE5, 0xB1, 0x8F}, 53 }, /* 屏 */
  { {0xE5, 0xB9, 0x95}, 54 }, /* 幕 */
  { {0xE4, 0xBF, 0x9D}, 55 }, /* 保 */
  { {0xE5, 0xAD, 0x98}, 56 }, /* 存 */
  { {0xE5, 0x88, 0xA0}, 57 }, /* 删 */
  { {0xE9, 0x99, 0xA4}, 58 }, /* 除 */
  { {0xE6, 0xB7, 0xBB}, 59 }, /* 添 */
  { {0xE5, 0x8A, 0xA0}, 60 }, /* 加 */
  { {0xE6, 0x81, 0xA2}, 61 }, /* 恢 */
  { {0xE5, 0xA4, 0x8D}, 62 }, /* 复 */
  { {0xE5, 0x9B, 0xBA}, 63 }, /* 固 */
  { {0xE4, 0xBB, 0xB6}, 64 }, /* 件 */
  { {0xE5, 0x90, 0xAF}, 65 }, /* 启 */
  { {0xE5, 0xB7, 0xB2}, 66 }, /* 已 */
  { {0xE5, 0xAE, 0x8C}, 67 }  /* 完 */
};
#define ZH_MENU_N 68


/* 查 UTF-8 三字节 -> 汉字下标, 找不到返回 -1 */
int zhMenuIndex(const uint8_t* p) {
  for (int i = 0; i < ZH_MENU_N; i++)
    if (p[0] == ZH_MENU_MAP[i].b[0] && p[1] == ZH_MENU_MAP[i].b[1] && p[2] == ZH_MENU_MAP[i].b[2])
      return ZH_MENU_MAP[i].idx;
  return -1;
}

/*__V58_NEW_BLOCK_START__*/
static const uint16_t ZH_NEW_FONT[][16] = {
  { 0x1000, 0x11FC, 0x1064, 0x1244, 0x1E44, 0xF044, 0x5044, 0x1044, 0x1044, 0x16C4, 0x1C84, 0x1184, 0x0304, 0x061C, 0x1C18, 0x0000 }, /* 切 */
  { 0x1080, 0x1080, 0x11F0, 0x1320, 0x7E60, 0x17F8, 0x1248, 0x1A48, 0xF248, 0x17FE, 0x10E0, 0x10A0, 0x1110, 0x160E, 0x7C00, 0x0000 }, /* 换 */
  { 0x0002, 0x7F82, 0x1002, 0x3232, 0x2232, 0x7F32, 0x0932, 0x0832, 0x5D32, 0x1832, 0x0832, 0x0882, 0x1E02, 0xE006, 0x000C, 0x0000 }, /* 到 */
  { 0x0040, 0x7E40, 0x10F8, 0x1098, 0x3198, 0x21B6, 0x7D92, 0x75FE, 0x7592, 0xF5B2, 0x3592, 0x3592, 0x3D12, 0x3712, 0x0214, 0x0000 }, /* 确 */
  { 0x0300, 0x0180, 0x7FFC, 0x4004, 0x4004, 0x3FFC, 0x0180, 0x0180, 0x1980, 0x19F8, 0x1980, 0x3980, 0x2580, 0x6380, 0xC0FE, 0x0000 }, /* 定 */
  { 0x7F80, 0x6600, 0x26FC, 0x2644, 0x3E4C, 0x2648, 0x2648, 0x3E48, 0x2630, 0x2630, 0x2730, 0xF678, 0x06CC, 0x0786, 0x0602, 0x0000 }, /* 取 */
  { 0x0000, 0x2020, 0x3126, 0x19A4, 0x00A8, 0xC1FE, 0x6102, 0x0902, 0x09FE, 0x1102, 0x1102, 0x11FE, 0x2102, 0x2102, 0x6106, 0x410C }, /* 消 */
  { 0x00F0, 0x2198, 0x1118, 0x0118, 0xC10E, 0x6300, 0x17F8, 0x1108, 0x1098, 0x2090, 0x2060, 0x2060, 0x60F0, 0x470E, 0x4C02, 0x0000 }, /* 没 */
  { 0x0100, 0x0300, 0x7FFE, 0x0600, 0x0400, 0x0FF8, 0x1C18, 0x3FF8, 0x6C18, 0x4C18, 0x0FF8, 0x0C18, 0x0C18, 0x0C18, 0x0430, 0x0000 }, /* 有 */
  { 0x0400, 0x0600, 0x0FE0, 0x1C40, 0x33C0, 0x6380, 0x06E0, 0x3C38, 0x7FFE, 0x1910, 0x1FF0, 0x19B0, 0x1910, 0x1FF0, 0x1810, 0x0000 }, /* 备 */
  { 0x0800, 0x0890, 0x0890, 0x1998, 0x1108, 0x3308, 0x7604, 0xDFFE, 0x1048, 0x10C8, 0x1088, 0x1088, 0x1188, 0x1708, 0x1638, 0x0000 }, /* 份 */
  { 0x0000, 0x0000, 0x7FFE, 0x0180, 0x0180, 0x0180, 0x1180, 0x11F8, 0x11F8, 0x1180, 0x1180, 0x1180, 0x1180, 0x1180, 0xFFFE, 0x0000 }, /* 正 */
  { 0x0100, 0x0300, 0x0300, 0x7FFE, 0x0400, 0x0460, 0x0860, 0x1860, 0x3BFC, 0x6820, 0x4820, 0x0820, 0x0860, 0x0BFE, 0x0800, 0x0000 }, /* 在 */
  { 0x0000, 0x3FF8, 0x3180, 0x0180, 0x7FFE, 0x0180, 0x3188, 0x1188, 0x1FF8, 0x1188, 0x1FF8, 0x0100, 0x3FFC, 0x0100, 0xFFFE, 0x0000 }, /* 重 */
  { 0x0000, 0x0180, 0x1FFC, 0x1804, 0x1004, 0x1004, 0x1FFC, 0x1000, 0x1000, 0x13FC, 0x1206, 0x1206, 0x1206, 0x3206, 0x63FE, 0x4204 }, /* 启 */
  { 0x0000, 0x0C20, 0x7FFE, 0x0C20, 0x0020, 0x3FF8, 0x0208, 0x3388, 0x18B0, 0x0980, 0x7FFE, 0x03C0, 0x07A0, 0x1D98, 0x718E, 0x4180 }, /* 菜 */
  { 0x0000, 0x0820, 0x0C20, 0x0660, 0x1FF8, 0x1108, 0x1188, 0x1FF8, 0x1108, 0x1FF8, 0x1108, 0x0180, 0x7FFE, 0x0100, 0x0100, 0x0100 }, /* 单 */
  { 0x2010, 0x2010, 0x23BC, 0x3916, 0x417E, 0x7B14, 0xF390, 0xB090, 0x7EBE, 0x3390, 0x3390, 0x3910, 0x3390, 0x36D0, 0x043C, 0x0000 }, /* 键 */
  { 0x0804, 0x68FC, 0x6880, 0x6880, 0x7E80, 0x60EC, 0x60EC, 0x60A8, 0x7CA8, 0x6DB8, 0x6D90, 0x6D38, 0x4D6C, 0x4FC6, 0x0782, 0x0000 }, /* 版 */
  { 0x0000, 0x0180, 0x0180, 0x0100, 0x7FFE, 0x03C0, 0x03C0, 0x0560, 0x0D30, 0x1918, 0x310C, 0x6FF6, 0x4180, 0x0100, 0x0180, 0x0180 }, /* 本 */
  { 0x0000, 0x7FFC, 0x6004, 0x6004, 0x67E4, 0x6424, 0x6424, 0x6424, 0x6424, 0x67E4, 0x6004, 0x6004, 0x7FFC, 0x6004, 0x6004, 0x0000 }, /* 回 */
  { 0x0000, 0x63F8, 0x3208, 0x0318, 0x0308, 0x7208, 0x13F8, 0x1204, 0x13D8, 0x1270, 0x1330, 0x13D8, 0x1384, 0x3C00, 0x47FE, 0x0000 }, /* 退 */
  { 0x0830, 0x0C20, 0x0460, 0xFFFE, 0x0000, 0x3E0C, 0x226C, 0x3E4C, 0x324C, 0x224C, 0x3E4C, 0x226C, 0x220C, 0x220C, 0x2618, 0x0000 }, /* 前 */
  { 0x2098, 0x3098, 0x1098, 0x03FE, 0x0098, 0x0098, 0xF198, 0x17FE, 0x1098, 0x1198, 0x1118, 0x1718, 0x3410, 0x4F00, 0x03FE, 0x0000 }, /* 进 */
  { 0x003C, 0x1C06, 0x1406, 0x7F06, 0x5506, 0x553E, 0x5560, 0x7760, 0x6360, 0x6160, 0x7F60, 0x4161, 0x4163, 0x7F62, 0x413E, 0x0000 }, /* 配 */
  { 0x0000, 0x7FFC, 0x6004, 0x7B94, 0x6AD4, 0x6E74, 0x6664, 0x6664, 0x6E74, 0x7BD4, 0x7194, 0x6104, 0x6004, 0x6004, 0x601C, 0x0000 }, /* 网 */
  { 0x0000, 0x2030, 0x31F8, 0x1118, 0x0118, 0x0118, 0xF30E, 0x37F8, 0x3198, 0x3098, 0x30D0, 0x3470, 0x3860, 0x31D8, 0x3F0E, 0x0C02 }, /* 设 */
  { 0x3FFC, 0x2644, 0x3FFC, 0x0100, 0x7FFE, 0x0100, 0x1FF0, 0x1810, 0x1FF0, 0x1810, 0x1FF0, 0x1810, 0x1810, 0x1818, 0x0000, 0x0000 }, /* 置 */
  { 0x0040, 0x18C0, 0x1840, 0xFFF8, 0x18C8, 0x1CC8, 0x7988, 0x59C8, 0x19EA, 0x1B0E, 0x3E06, 0x0000, 0x2048, 0x2664, 0x6226, 0x0000 }, /* 热 */
  { 0x0300, 0x0300, 0x03FC, 0x0300, 0x0300, 0x1FF8, 0x1018, 0x1018, 0x1018, 0x1FF8, 0x1008, 0x0008, 0x264C, 0x2264, 0x6226, 0x0000 }, /* 点 */
  { 0x0000, 0x3FF8, 0x0008, 0x0008, 0x2008, 0x2008, 0x3FF8, 0x2008, 0x2000, 0x2000, 0x2002, 0x2002, 0x2002, 0x2006, 0x1FFC, 0x0000 }, /* 已 */
  { 0x0820, 0x0C60, 0x06C0, 0x3FFC, 0x0100, 0x0100, 0x0100, 0x3FFE, 0x03C0, 0x01C0, 0x0240, 0x0620, 0x0C10, 0x380E, 0x6006, 0x0000 }, /* 关 */
  { 0x1000, 0x1BFC, 0x4886, 0x4086, 0x4FF6, 0x4186, 0x4386, 0x4286, 0x4686, 0x4C86, 0x5086, 0x4086, 0x4186, 0x4004, 0x400C, 0x0000 }, /* 闭 */
  { 0x0000, 0x3FFC, 0x0420, 0x0420, 0x0420, 0x0420, 0x7FFE, 0x7FFE, 0x0420, 0x0420, 0x0420, 0x0C20, 0x1820, 0x3020, 0x6020, 0x0000 }, /* 开 */
  { 0x0000, 0x0040, 0x60C0, 0x32C2, 0x13FE, 0x0120, 0x0320, 0xF3FC, 0x3020, 0x3020, 0x37FE, 0x3020, 0x3020, 0x3020, 0x6F00, 0x03FE }, /* 连 */
  { 0x0000, 0x0180, 0x0100, 0x0100, 0x0100, 0x0100, 0x0180, 0x01FC, 0x0100, 0x0100, 0x0100, 0x0100, 0x0100, 0x0180, 0xFFFE, 0x0000 }, /* 上 */
  { 0x0000, 0x0300, 0x7FFE, 0x0000, 0x0FF0, 0x0810, 0x0FF0, 0x0000, 0x7FFE, 0x4002, 0x47E2, 0x0420, 0x0C22, 0x0822, 0x7022, 0x403E }, /* 亮 */
  { 0x0000, 0x0080, 0x1FFE, 0x3210, 0x3310, 0x3FFE, 0x3210, 0x33F0, 0x3000, 0x37F8, 0x3318, 0x3110, 0x20E0, 0x20E0, 0x67BC, 0x4E0E }, /* 度 */
  { 0x0000, 0x0300, 0x3FF8, 0x0830, 0x0820, 0x0C60, 0xFFFE, 0x0000, 0x0000, 0x1FF0, 0x1010, 0x1FF0, 0x1010, 0x1010, 0x1FF0, 0x1010 }, /* 音 */
  { 0x1FF0, 0x1018, 0x1FF8, 0x1018, 0x0000, 0xFFFE, 0x1FF0, 0x1118, 0x1FF8, 0x1108, 0x1FF0, 0x0180, 0x0100, 0x7FFE, 0x0000, 0x0000 }, /* 量 */
  { 0x0000, 0x0180, 0x0100, 0x0180, 0x1FF8, 0x0100, 0x0100, 0x7FFC, 0x0100, 0x1900, 0x1988, 0x19F8, 0x1D00, 0x1700, 0x23FC, 0x403C }, /* 走 */
  { 0x0000, 0x3FF0, 0x0030, 0x0830, 0x0820, 0x0820, 0x1820, 0x1FFC, 0x0FFC, 0x0004, 0x7FE4, 0x0004, 0x0004, 0x001C, 0x0018, 0x0000 }, /* 马 */
  { 0x1800, 0x1800, 0x19FE, 0x1A10, 0x5E10, 0x5C10, 0x5810, 0xD810, 0x1810, 0x1810, 0x1C10, 0x3610, 0x2010, 0x6010, 0x4070, 0x0000 }, /* 灯 */
  { 0x103C, 0x33E0, 0x1348, 0x3158, 0x79F0, 0x10F0, 0x11F0, 0x3B4C, 0xF7FE, 0x1264, 0x136C, 0x136C, 0x1264, 0x33FC, 0x6204, 0x0000 }, /* 播 */
  { 0x0000, 0x1860, 0x1860, 0x18D0, 0x1898, 0x7F8E, 0x1B02, 0x3EF8, 0x3C40, 0x7964, 0x592C, 0xD9A8, 0x1898, 0x1810, 0x1A3A, 0x1000 }, /* 检 */
  { 0x0000, 0x0180, 0x0180, 0x7FFE, 0x07E0, 0x1D38, 0x710C, 0x4180, 0x1810, 0x1810, 0x0FF0, 0x1810, 0x1FF0, 0x0000, 0x7FFE, 0x0000 }, /* 查 */
  { 0x0000, 0x7FFE, 0x0100, 0x1FF8, 0x3188, 0x3108, 0x1FF8, 0x3108, 0x3FF8, 0x0180, 0x0900, 0x0700, 0x0700, 0x1CE0, 0x703E, 0x0000 }, /* 更 */
  { 0x0000, 0x0800, 0x7F7C, 0x2260, 0x3260, 0x1E60, 0x7FFE, 0x0C6C, 0x0C6C, 0x7FEC, 0x1E4C, 0x3F4C, 0x2D4C, 0x6CCC, 0x4C8C, 0x190C }, /* 新 */
  { 0x0000, 0x00C0, 0x27FE, 0x1000, 0x0110, 0xC348, 0x6694, 0x15B0, 0x13D8, 0x10C4, 0x21AC, 0x2330, 0x2710, 0x7948, 0x4186, 0x4100 }, /* 滚 */
};

static const struct { uint8_t b[3]; uint8_t idx; } ZH_NEW_MAP[] = {
  { {0xE5, 0x88, 0x87}, 0 }, /* 切 */
  { {0xE6, 0x8D, 0xA2}, 1 }, /* 换 */
  { {0xE5, 0x88, 0xB0}, 2 }, /* 到 */
  { {0xE7, 0xA1, 0xAE}, 3 }, /* 确 */
  { {0xE5, 0xAE, 0x9A}, 4 }, /* 定 */
  { {0xE5, 0x8F, 0x96}, 5 }, /* 取 */
  { {0xE6, 0xB6, 0x88}, 6 }, /* 消 */
  { {0xE6, 0xB2, 0xA1}, 7 }, /* 没 */
  { {0xE6, 0x9C, 0x89}, 8 }, /* 有 */
  { {0xE5, 0xA4, 0x87}, 9 }, /* 备 */
  { {0xE4, 0xBB, 0xBD}, 10 }, /* 份 */
  { {0xE6, 0xAD, 0xA3}, 11 }, /* 正 */
  { {0xE5, 0x9C, 0xA8}, 12 }, /* 在 */
  { {0xE9, 0x87, 0x8D}, 13 }, /* 重 */
  { {0xE5, 0x90, 0xAF}, 14 }, /* 启 */
  { {0xE8, 0x8F, 0x9C}, 15 }, /* 菜 */
  { {0xE5, 0x8D, 0x95}, 16 }, /* 单 */
  { {0xE9, 0x94, 0xAE}, 17 }, /* 键 */
  { {0xE7, 0x89, 0x88}, 18 }, /* 版 */
  { {0xE6, 0x9C, 0xAC}, 19 }, /* 本 */
  { {0xE5, 0x9B, 0x9E}, 20 }, /* 回 */
  { {0xE9, 0x80, 0x80}, 21 }, /* 退 */
  { {0xE5, 0x89, 0x8D}, 22 }, /* 前 */
  { {0xE8, 0xBF, 0x9B}, 23 }, /* 进 */
  { {0xE9, 0x85, 0x8D}, 24 }, /* 配 */
  { {0xE7, 0xBD, 0x91}, 25 }, /* 网 */
  { {0xE8, 0xAE, 0xBE}, 26 }, /* 设 */
  { {0xE7, 0xBD, 0xAE}, 27 }, /* 置 */
  { {0xE7, 0x83, 0xAD}, 28 }, /* 热 */
  { {0xE7, 0x82, 0xB9}, 29 }, /* 点 */
  { {0xE5, 0xB7, 0xB2}, 30 }, /* 已 */
  { {0xE5, 0x85, 0xB3}, 31 }, /* 关 */
  { {0xE9, 0x97, 0xAD}, 32 }, /* 闭 */
  { {0xE5, 0xBC, 0x80}, 33 }, /* 开 */
  { {0xE8, 0xBF, 0x9E}, 34 }, /* 连 */
  { {0xE4, 0xB8, 0x8A}, 35 }, /* 上 */
  { {0xE4, 0xBA, 0xAE}, 36 }, /* 亮 */
  { {0xE5, 0xBA, 0xA6}, 37 }, /* 度 */
  { {0xE9, 0x9F, 0xB3}, 38 }, /* 音 */
  { {0xE9, 0x87, 0x8F}, 39 }, /* 量 */
  { {0xE8, 0xB5, 0xB0}, 40 }, /* 走 */
  { {0xE9, 0xA9, 0xAC}, 41 }, /* 马 */
  { {0xE7, 0x81, 0xAF}, 42 }, /* 灯 */
  { {0xE6, 0x92, 0xAD}, 43 }, /* 播 */
  { {0xE6, 0xA3, 0x80}, 44 }, /* 检 */
  { {0xE6, 0x9F, 0xA5}, 45 }, /* 查 */
  { {0xE6, 0x9B, 0xB4}, 46 }, /* 更 */
  { {0xE6, 0x96, 0xB0}, 47 }, /* 新 */
  { {0xE6, 0xBB, 0x9A}, 48 }, /* 滚 */
};
#define ZH_NEW_N 49

/* 查 v58 新字库里的字形, 返回下标, 没有就 -1 */
int zhNewIndex(const uint8_t* p) {
  for (int i = 0; i < ZH_NEW_N; i++)
    if (p[0] == ZH_NEW_MAP[i].b[0] && p[1] == ZH_NEW_MAP[i].b[1] && p[2] == ZH_NEW_MAP[i].b[2])
      return ZH_NEW_MAP[i].idx;
  return -1;
}

/* 画 v58 新字库里的一个汉字 */
void drawZhNew16(int idx, int x, int y, bool invert) {
  if (idx < 0) return;
  for (int r = 0; r < 16; r++) {
    uint16_t row = ZH_NEW_FONT[idx][r];
    for (int c = 0; c < 16; c++) {
      bool on = (row >> (15 - c)) & 1;
      display.drawPixel(x + c, y + r, (on != invert) ? SSD1306_WHITE : SSD1306_BLACK);
    }
  }
}

/* 混排绘制: 汉字用 v58 新字库(16px), 其余 ASCII 用内置 6px 小字。
   返回结束 x。 */
int drawZhNew(const char* s, int x, int y, bool invert) {
  int cx = x;
  for (const char* p = s; *p; ) {
    if ((uint8_t)*p >= 0xE0) {
      drawZhNew16(zhNewIndex((const uint8_t*)p), cx, y, invert);
      cx += 16; p += 3;
    } else {
      display.setTextSize(1);
      display.setTextColor(invert ? SSD1306_BLACK : SSD1306_WHITE);
      display.setCursor(cx, y + 4);
      display.print(*p);
      cx += 6; p++;
    }
  }
  return cx;
}

void drawItem(const char* txt, int x, int y, int w, bool sel);

/* ============ v58 版本切换确认框 ============
   target = 另一个分区, ver = 那版的版本号字符串
   返回 true = 用户选了确定 */
static int  g_okSel = 0;          /* 0 = 确定, 1 = 取消 */

void drawSwitchBox(const char* ver, bool hasBackup) {
  if (!screenOK) return;
  display.clearDisplay();
  if (!hasBackup) {
    drawZhNew("没有备份", 0, 8, false);
    display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 30); display.print("no firmware in other slot");
    display.setCursor(0, 44); display.print("K3 = back");
    display.display();
    return;
  }
  drawZhNew("切换到", 0, 4, false);
  drawZhNew("v", 52, 4, false);
  display.setTextSize(2); display.setTextColor(SSD1306_WHITE);
  display.setCursor(60, 2); display.print(ver);
  /* 两个选项 */
  drawItem("OK",   10, 34, 52,  (g_okSel == 0));
  drawItem("NO",   72, 34, 52,  (g_okSel == 1));
  display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 54); display.print("K1/K2 sel  K3 ok");
  display.display();
}

/* 弹框等用户按键: 返回 0=确定 1=取消 -1=超时 */
int askSwitch(const char* ver, bool hasBackup) {
  if (!hasBackup) {
    drawSwitchBox(ver, false);
    unsigned long t0 = millis();
    while (millis() - t0 < 4000) {
      if (digitalRead(BTN_REPLAY) == LOW) break;
      delay(20);
    }
    return 1;
  }
  g_okSel = 0;
  drawSwitchBox(ver, true);
  unsigned long t0 = millis();
  while (millis() - t0 < 12000) {
    if (digitalRead(BTN_K1) == LOW) {
      g_okSel = 0; drawSwitchBox(ver, true);
      while (digitalRead(BTN_K1) == LOW) delay(20);
    } else if (digitalRead(BTN_BRIGHT) == LOW) {
      g_okSel = 1; drawSwitchBox(ver, true);
      while (digitalRead(BTN_BRIGHT) == LOW) delay(20);
    } else if (digitalRead(BTN_REPLAY) == LOW) {
      while (digitalRead(BTN_REPLAY) == LOW) delay(20);
      return g_okSel;
    }
    delay(20);
  }
  return -1;                       /* 超时 = 不动 */
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

/* v56: 混排绘制 —— 中文字用点阵, ASCII 用内置小字.
   返回占用宽度. */
int drawMixed(const char* s, int x, int y, bool invert) {
  if (invert) {
    /* 先估宽: 中文16px, 英文6px */
    int w = 0;
    for (const char* p = s; *p; ) {
      if ((uint8_t)*p >= 0xE0) { w += 16; p += 3; }
      else { w += 6; p++; }
    }
    display.fillRect(x - 1, y - 1, w + 2, 18, SSD1306_WHITE);
  }
  int cx = x;
  display.setTextColor(invert ? SSD1306_BLACK : SSD1306_WHITE);
  for (const char* p = s; *p; ) {
    if ((uint8_t)*p >= 0xE0) {
      drawZh16(zhMenuIndex((const uint8_t*)p), cx, y, invert);
      cx += 16;
      p += 3;
    } else {
      char b[2] = { *p, 0 };
      display.setCursor(cx, y + 4);
      display.print(b);
      cx += 6;
      p++;
    }
  }
  display.setTextColor(SSD1306_WHITE);
  return cx - x;
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
    case 4:  return "检查更新";
    default: return "回滚";
  }
}

void drawMenu() {
  if (!screenOK) return;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  if (menuActive == 1) {
    /* v65: 主菜单全中文。一屏 4 项(每项 16px 高), 光标走出屏幕就滚动。 */
    const int ROWS = 4;
    if (menuCursor < menuTop) menuTop = menuCursor;
    if (menuCursor >= menuTop + ROWS) menuTop = menuCursor - ROWS + 1;
    if (menuTop > MENU_ITEMS - ROWS) menuTop = MENU_ITEMS - ROWS;
    if (menuTop < 0) menuTop = 0;

    for (int r = 0; r < ROWS; r++) {
      int i = menuTop + r;
      if (i >= MENU_ITEMS) break;
      int y = r * 16;
      bool sel = (i == menuCursor);
      if (sel) display.fillRect(0, y, 124, 16, SSD1306_WHITE);
      const char* nm = menuNameCn(i);
      drawZhNew(nm, 1, y, sel);            /* 汉字: 选中时反色 */
      /* 名字占多少像素: 每个汉字 16px */
      int w = 0;
      for (const char* q = nm; *q; q += 3) w += 16;
      char v[12];
      menuValue(v, i);
      display.setTextSize(1);
      display.setTextColor(sel ? SSD1306_BLACK : SSD1306_WHITE);
      int vx = w + 6;
      int vw = strlen(v) * 6;
      if (vx + vw > 124) vx = 124 - vw;
      display.setCursor(vx, y + 4);
      display.print(v);
    }
    /* 右侧滚动条 */
    if (MENU_ITEMS > ROWS) {
      int h = 60 / MENU_ITEMS;
      display.drawFastVLine(126, 2, 60, SSD1306_WHITE);
      display.fillRect(125, 2 + menuTop * h, 3, h + 1, SSD1306_WHITE);
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
    } else if (menuCursor == 5) {   /* v56: ROLLBACK 强制回滚 */
      menuActive = 4;
      menuSub = 0;
      drawRollbackConfirm();
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
  } else if (menuActive == 4) {     /* v56: 回滚确认页 */
    if (menuSub == 1) {             /* 选了 DO IT -> 真回滚(会重启) */
      menuActive = 0;
      if (!rollbackToOtherPartition()) {
        screen2("ROLLBACK FAIL", "no backup");
        delay(1800);
        showIdle();
      }
    } else {                        /* CANCEL */
      menuActive = 1;
      menuCursor = 5;
      drawMenu();
    }
  }
}

void menuTick() {
  /* v65: 菜单里按 K4 = 退出菜单, 回主页面 */
  {
    static bool k4Was = false;
    bool k4 = (digitalRead(BTN_TALK) == LOW);
    if (k4 && !k4Was) {
      delay(25);
      if (digitalRead(BTN_TALK) == LOW) {
        k4Was = true;
        while (digitalRead(BTN_TALK) == LOW) delay(10);
        Serial.println(">>> K4 -> exit menu");
        menuExit();
        return;
      }
    }
    if (!k4) k4Was = false;
  }

  /* K1 = 上 / 减 */
  bool k1 = digitalRead(BTN_K1) == LOW;
  if (k1 && !k1Was) {
    delay(30);
    if (digitalRead(BTN_K1) == LOW) {
      menuLastMs = millis();
      if (menuActive == 1)      { menuCursor = (menuCursor + MENU_ITEMS - 1) % MENU_ITEMS; drawMenu(); }
      else if (menuActive == 2) { menuMove(-1); drawMenu(); }
      else if (menuActive == 3) { menuSub = 0; drawMenu(); }
      else if (menuActive == 4) { menuSub = 0; drawRollbackConfirm(); }
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
      else if (menuActive == 4) { menuSub = 1; drawRollbackConfirm(); }
    }
  }
  k2Was = k2;

  /* v66: 菜单里 K3 = 确认(进入/生效)。松手就触发, 不管按多久 ——
     以前要求"按得短于 400 毫秒"才算确认, 400~800 毫秒这段什么都不发生,
     她按 0.5 秒左右, 正好落在死区里, 所以觉得"确认键没反应"。
     退出菜单改用 K4, 不再用 K3 长按。 */
  bool k3 = digitalRead(BTN_REPLAY) == LOW;
  if (!k3 && k3Was) {
    delay(10);
    Serial.println(">>> K3 confirm");
    menuEnterShort();
    k3Was = false;
    return;
  }
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
    /* ===== v57: 全局长按 (任何界面都有效) =====
         K3(#)  长按 3 秒 -> 开热点进配网 (连按也算, 累积够 3 秒即触发)
         K1(^)  长按 3 秒 -> 重装最近的备份固件 (另一个分区, 不带联网)
         K2(v)  长按 3 秒 -> 刷最新正式版 (先问 GitHub 最新版本号再刷)
       三个键都只在菜单外生效, 免得和菜单操作打架。 */
    {
      /* v63: 不再限制"只在菜单外" —— 长按在菜单里也要能触发 */
      static unsigned long t3 = 0, t1 = 0, t2 = 0;
      static bool d3 = false, d1 = false, d2 = false;
      static bool d12 = false; static unsigned long t12 = 0;   /* v73 K1+K2 自检屏 */
      bool k3 = (digitalRead(BTN_REPLAY) == LOW);
      bool k1 = (digitalRead(BTN_K1)     == LOW);
      bool k2 = (digitalRead(BTN_BRIGHT) == LOW);
      unsigned long now = millis();

      /* ---- K3: 配网 ---- */
      if (k3) {
        if (!d3) { d3 = true; t3 = now; }
        else if (now - t3 >= 3000) {
          Serial.println(">>> K3 held 3s -> config portal");
          if (screenOK) {
            display.clearDisplay();
            drawZhNew("配网", 0, 6, false);
            display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
            display.setCursor(44, 10); display.print("starting...");
            display.setCursor(0, 32); display.print("release K3");
            display.display();
          }
          delay(500);
          while (digitalRead(BTN_REPLAY) == LOW) delay(20);
          runConfigPortal();                 /* 不返回 */
        }
      } else d3 = false;

      /* ---- v73: K1+K2 同按 1 秒 -> 按键自检屏 (v64 误删, 这里加回) ---- */
      if (k1 && k2) {
        if (!d12) { d12 = true; t12 = now; }
        else if (now - t12 >= 1000) {
          Serial.println(">>> K1+K2 held 1s -> key diag");
          d12 = false;
          while (digitalRead(BTN_K1) == LOW || digitalRead(BTN_BRIGHT) == LOW) delay(20);
          showKeyDiag();
          k1Was = k2Was = k3Was = false;
        }
      } else d12 = false;

      /* ---- K1 / K2: 两个分区互切 (不联网) ----
         K1 = 切到另一个分区(屏幕显示那版版本号, 确认后切)
         K2 = 和 K1 是同一个动作 —— 因为分区只有两个, 来回按就是来回切。
              之所以两个键都做, 是她要求的: 后退/前进都能按。 */
      if ((k1 && !k2) || (k2 && !k1)) {
        bool isK1 = (k1 && !k2);
        if (!d1 && !d2) { d1 = true; d2 = true; t1 = now; t2 = now; }
        else if (now - (isK1 ? t1 : t2) >= 5000) {
          Serial.printf(">>> %s held 5s -> switch slot\n", isK1 ? "K1" : "K2");
          while (digitalRead(BTN_K1) == LOW || digitalRead(BTN_BRIGHT) == LOW) delay(20);
          doSwitchSlot();
        }
      } else { d1 = false; d2 = false; }
    }

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
          toggleSoftAp();                 /* v61: 短按 K4 = 开/关热点 */
          Serial.println(">>> K4 short press -> toggle hotspot");
        }
        delay(300);
      }
    }
    /* ===== v64: 首页上 K1 / K2 / K3 —— 随便哪个都能进菜单 =====
       她的要求: 三个键里点哪个都行, 别让她猜。
       长按动作(3 秒配网 / 5 秒切版本)由 loop 顶部的全局计时负责, 互不影响。 */
    else if (Serial.available()) {
      /* v73: 串口 diag —— 不碰屏幕，远程看按键电平 */
      String cmd = Serial.readStringUntil('\n'); cmd.trim();
      if (cmd == "diag") {
        Serial.printf("DIAG K1=%d K2=%d K3=%d K4=%d bright=%d slot=%d menu=%d heap=%u\n",
          digitalRead(BTN_K1), digitalRead(BTN_BRIGHT), digitalRead(BTN_REPLAY),
          digitalRead(BTN_TALK), g_bright, menuActive, (unsigned)ESP.getFreeHeap());
      } else {
        Serial.printf("?cmd=%s\n", cmd.c_str());
      }
    }
    else if (digitalRead(BTN_K1) == LOW ||
             digitalRead(BTN_BRIGHT) == LOW ||
             digitalRead(BTN_REPLAY) == LOW) {
      delay(30);
      if (g_bright == 0) { g_bright = 2; applyBrightness(); }   /* 熄屏先点亮 */
      menuActive = 1;
      menuCursor = 0;
      menuLastMs = millis();
      drawMenu();
      Serial.println(">>> menu open (any key)");
      /* 等松手, 免得刚进菜单就被判成一次"选择" */
      unsigned long tr = millis();
      while ((digitalRead(BTN_K1) == LOW ||
              digitalRead(BTN_BRIGHT) == LOW ||
              digitalRead(BTN_REPLAY) == LOW) && millis() - tr < 2500) {
        delay(10);
      }
      k1Was = false; k2Was = false; k3Was = false;   /* 清边沿状态 */
      k3Fired = false;
      menuLastMs = millis();
    }
        /* v54: 菜单外 K1/K2 无反应 (她定的: 改亮度/音量/走马灯一律进 K3 菜单)
           v58: 这两个键现在是"长按 5 秒切换版本", 短按不再弹提示, 免得她以为坏了
                 (长按的反馈在屏幕上给足 12 秒) */
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
