---
generated_by: "OpenAI Codex (GPT-6; exact variant not exposed)"
timestamp: "2026-11-08T13:35:38-06:00"
---
# Errors

## 2026-11-08 — overly broad prefix rename
Changing model prefix w_ to t_ also changed graphics_draw_* and window_* SDK names. Native compiler caught the misspellings; restored SDK names and rebuilt. For reused code, rename explicit model symbols, not arbitrary letter-underscore substrings. Host-only model tests cannot prove native API calls compile.

## 2026-11-08 — scaffold health
The canonical workflow-python scaffold health check failed before implementation. Its generic Python profile requirements are not proof of a Pebble watchface. Use task.md's explicit host/native/bundle contract; do not claim the scaffold check passed.
