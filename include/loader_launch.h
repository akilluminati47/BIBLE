#ifndef LOADER_LAUNCH_H
#define LOADER_LAUNCH_H

#include <stddef.h>
#include <tamtypes.h>

typedef void (*LoaderPollEmergencyComboWindowFn)(u64 *window_deadline_ms);

// BIBLE: LoaderRunLaunchWorkflow returns these when a page's buttons are held together instead of launching one
#define LOADER_LAUNCH_VIDEO_PAGE 2 // TRIANGLE + CROSS: the video mode selector
#define LOADER_LAUNCH_KEYS_PAGE 3  // L2 + R2: the launch keys page

int LoaderRunLaunchWorkflow(int splash_early_presented,
                            int *hotkey_launches_enabled,
                            int *block_hotkeys_until_release,
                            int pad_button,
                            int num_buttons,
                            int is_psx_desr,
                            int config_source,
                            int native_video_mode,
                            const u8 *romver,
                            size_t romver_size,
                            char **execpaths,
                            u64 *rescue_combo_deadline,
                            LoaderPollEmergencyComboWindowFn poll_emergency_combo_window);

#endif
