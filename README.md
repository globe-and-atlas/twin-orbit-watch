---
generated_by: "OpenAI Codex (GPT-6; exact variant not exposed)"
timestamp: "2026-11-08T13:35:38-06:00"
---
# Twin Orbit

Two overlapping, offset clock tracks. The upper-left ring shows hours with a larger hollow marker; the lower-right ring shows minutes with a smaller solid dot. Read the clock position or the optional upright numeric values at each center. The hour ring keeps conventional12-hour geometry; numeric hours support watch-default,12-hour, or24-hour format.

Targets: Pebble Time2 (Emery200×228) and Round2 (Gabbro260×260). Settings offer Night, Paper, Mint, Ice, Rose, Monochrome, and custom background/text/hour/minute colors. Optional center values, digital readout, and dateOff/ISO/US/European. Defaults show center values and digital time, date off. Minute updates, no continuous timer, no network service.

Production: `python3 execution/build.py`; `python3 execution/verify.py`; install dist/Twin-Orbit-0.1.0.pbw through the Pebble app/SDK. Host: `python3 execution/build.py --host-only` or `python3 -m pytest -q`.

Native previews: build_fixture.py, then capture_native.py --platform emery/gabbro --reset-emulator. Establish exclusive emulator ownership before reset. Flash backups and diagnostics stay in.tmp/. Fixtures never copy into dist. Rebuild clean production after captures. build_preview.py assembles the native comparison without resizing source pixels.

Published: [Twin Orbit on the Pebble app store](https://apps.repebble.com/67373e8c182e4e86a7950434). Physical-watch legibility and battery endurance are unmeasured.
