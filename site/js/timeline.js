// One loop of the page: what a power on looks like with these settings, from measured numbers. Where each comes from:
//   POWER_S    0.72 s  lab burst frames (PCSX2, memory card): the first frame BIBLE draws
//   SPLASH_S   0.27 s  lab: how long the logo shows at Power-on Wait 0 ms (0.77 s to 1.04 s), on top of any wait
//   LAB_BLACK  7.40 s  lab: black from the splash to RIPPS2's first bright frame (7.41, 7.39 and 7.25 s in three runs)
//   CONSOLE    +2.44 s the user's SCPH-39001 with an SD2PSX: DIAG.TXT has the towers up 4.19 s into RIPPS2, the lab 1.75 s. Only that part
//                      was timed on the console: the ELF load before it is the lab's, so this one is an estimate
//   DISC_S     3.30 s  lab: what DISC_STOP = 1 adds at 0 ms, waiting on the drive. It is time-based, the drive is still starting, so a longer
//                      Power-on Wait uses it up (none at 6000 ms)
//   TOWERS_S   3.20 s  RIPPS2 src/ripps2bg.c, INTRO_UI_S: the menu comes in here, which is where a legacy theme takes over from the pillars
export const POWER_S = 0.72, SPLASH_S = 0.27, LAB_BLACK = 7.4, CONSOLE_EXTRA = 2.44, DISC_S = 3.3, TOWERS_S = 3.2, FADE_S = 0.25;

export function buildLoop(st) {
  const wait = (+st.wait || 0) / 1000;
  const disc = st.disc === '1' ? Math.max(0, DISC_S - wait) : 0;
  const black = LAB_BLACK + (st.black === 'console' ? CONSOLE_EXTRA : 0) + disc;
  const phases = [
    { id: 'power', label: 'Boot', d: POWER_S },
    { id: 'splash', label: 'BIBLE', d: wait + SPLASH_S, wait },
    { id: 'black', label: 'Black', d: black, disc },
    { id: 'towers', label: 'Towers', d: TOWERS_S },
  ];
  let t = 0;
  for (const p of phases) { p.at = t; t += p.d; }
  return { phases, total: t, wait, black, disc };
}

export function phaseAt(loop, t) {
  for (const p of loop.phases) if (t < p.at + p.d) return { phase: p, into: t - p.at };
  const p = loop.phases[loop.phases.length - 1];
  return { phase: p, into: p.d };
}
