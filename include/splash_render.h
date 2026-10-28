#ifndef SPLASH_RENDER_H
#define SPLASH_RENDER_H

#include <tamtypes.h>

int SplashRenderBegin(int logo_disp, int is_psx_desr);
void SplashRenderSetVideoMode(int cfg_mode, int native_mode);
void SplashRenderBeginFrame(void);
void SplashRenderDrawTextPx(int x, int y, u32 color, const char *text);
void SplashRenderDrawTextPxScaled(int x, int y, u32 color, const char *text, int scale);
void SplashRenderDrawRoundedRect(int x, int y, int w, int h, int radius, u32 color, unsigned int opacity_percent);
void SplashRenderRestoreBackgroundRect(int x, int y, int w, int h);
void SplashRenderPageBegin(void);          // BIBLE: a page over the dimmed logo, the buttons put away, fading in
void SplashRenderPageEnd(void);
int SplashRenderPageFade(void);            // BIBLE: the page's fade, 0..100
void SplashRenderPageBox(int x, int y, int w, int h);
int SplashRenderGlyphForKey(const char *key); // BIBLE: KEYS_ID name to a glyph id, -1 for none
int SplashRenderDrawGlyph(int id, int x, int y);
int SplashRenderGlyphSize(void);
int SplashRenderInfoLineY(void);           // BIBLE: the info line's y above the logo (LOGO_DISPLAY 2), else -1
int SplashRenderTextTopY(int block_h);     // BIBLE: where text block_h high starts above the logo, else -1
void SplashRenderSetGlyphs(int mode); // BIBLE: BIBLE_GLYPHS (0 none, 1 the face buttons, 2 all), before the splash begins
void SplashRenderSetSky(const unsigned int sky[3]); // BIBLE: BIBLE_COLOR, the sky's top, horizon and floor (0xRRGGBB)
void SplashRenderSetHotkeysVisible(int visible);
void SplashRenderSetLogoShimmerCountdown(u64 remaining_ms, u64 total_ms);
void SplashRenderPresent(void);
int SplashRenderIsActive(void);
void SplashRenderEnd(void);
int SplashRenderGetScreenWidth(void);
int SplashRenderGetScreenHeight(void);
int SplashRenderGetScreenCenterX(void);
int SplashRenderGetScreenCenterY(void);
int SplashRenderGetHotkeysX(void);
int SplashRenderGetHotkeysY(void);
int SplashRenderGetLogoX(void);
int SplashRenderGetLogoY(void);
int SplashRenderGetLogoWidth(void);
int SplashRenderGetLogoHeight(void);

#endif
