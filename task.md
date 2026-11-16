---
generated_by: "OpenAI Codex (GPT-6; exact variant not exposed)"
timestamp: "2026-11-08T13:30:46-06:00"
---
# Build Twin Orbit

Two overlapping, offset tracks indicate hours and minutes. Targets: Emery200×228, Gabbro260×260.

## Contract
- Directive: directives/build_watchface.md
- Execution: build.py, build_fixture.py, capture_native.py, verify.py
- Artifacts: dist/Twin-Orbit-0.1.0.pbw; media/native-comparison.png
- Store publication authorized below; no Git commit or push requested. Ignore secrets and SDK lock files.

## Validation
- [x] Emery binary builds.
- [x] Gabbro binary builds.
- [x] Hour marker travels on the upper-left orbit.
- [x] Minute marker travels on the lower-right orbit.
- [x] Hour marker uses a hollow ring.
- [x] Minute marker uses a solid dot.
- [x] Orbit tracks overlap.
- [x] Numeric hours honor forced12-hour mode.
- [x] Numeric hours honor forced24-hour mode.
- [x] Watch-default numeric format follows the system preference.
- [x] Hour orbit retains conventional12-hour geometry.
- [x] Six palettes are selectable.
- [x] Custom background is selectable.
- [x] Custom text color is selectable.
- [x] Custom hour color is selectable.
- [x] Custom minute color is selectable.
- [x] Center numeric labels can be hidden.
- [x] Digital readout can be hidden.
- [x] Date can be Off, ISO, US, or European.
- [x] Native Save applies settings.
- [x] Cancel preserves settings.
- [x] Settings survive restart.
- [x] Dial markers stay inside Emery bounds.
- [x] Dial markers stay inside the Gabbro circle.
- [x] Markers remain clear of center numeric labels.
- [x] Native crossing poses are inspected.
- [x] Full-day host tests pass.
- [x] Actual Clay tests pass.
- [x] Native Emery renders are inspected.
- [x] Native Gabbro renders are inspected.
- [x] Production excludes fixture controls.
- [x] Independent review passes.

Completed: native matrices, host/Clay tests, production bundle verification, and independent final review PASS.

## Store publication — 2026-11-08
User authorized publishing Twin Orbit with moving-marker/color GIF first and native screenshots on both targets.
- [x] Emery GIF shows both moving markers.
- [x] Gabbro GIF shows both moving markers.
- [x] Each GIF includes six palettes.
- [x] Emery public gallery begins with a GIF.
- [x] Gabbro public gallery begins with a GIF.
- [x] Emery public gallery includes four native stills.
- [x] Gabbro public gallery includes four native stills.
- [x] Public PBW matches the reviewed production artifact.
- [x] Public preview assets match staged assets.
- [x] Independent release review passes.
