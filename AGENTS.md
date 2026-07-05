# Global Codex Guidance

## Communication

- Ask a clarifying question when requirements are ambiguous and different answers would lead to meaningfully different implementations.
- Before asking, first inspect the repository, existing patterns, logs, or standard conventions when they can answer the question.
- Prefer one well-formed question over several small questions.
- When reporting work, distinguish verified facts from assumptions.

## Problem Ownership

- Treat observed failures, errors, warnings, and unexpected behavior as relevant until they are explained or explicitly scoped out by the user.
- Investigate root causes instead of masking symptoms with workarounds.
- Verify theories with concrete evidence such as source code, logs, command output, tests, traces, or runtime state.
- If evidence disproves a theory, discard it and continue from the new facts.
- Do not claim that something works, is safe, or will not affect a path unless it has been verified or clearly marked as an inference.

## Code Language

- Use English for code identifiers, comments, logs, errors, commit messages, and developer-facing text.
- Use Chinese or another non-English language only for intentional end-user-facing strings, product copy, or localization.

## Logging And Debugging

- For new or changed integration code, make failures diagnosable from logs alone where practical.
- Add structured logging at important decision points: incoming data, outgoing calls, return values, and error paths.
- Use appropriate log levels: debug, info, warn, and error.
- Log useful request and response details for external service integrations, while avoiding secrets and sensitive personal data.
- Do not silently swallow errors unless the fallback behavior is intentional and visible in logs or returned status.

## Verification

- Run the relevant tests, lint, type checks, or targeted reproduction steps when they are available and proportionate to the change.
- If verification cannot be run, explain what was not run and why.
- Prefer targeted checks for narrow changes and broader checks for shared behavior, cross-module contracts, or user-facing workflows.

## Memory Hygiene

- Save durable memory only for long-term truths: user preferences, hard constraints, stable project positioning, design philosophy, or pointers to external systems.
- Do not save in-progress decisions, current task state, latest test results, temporary debug findings, or one-session conclusions.
- Apply the 3-month test: if it is unlikely to remain true in three months, do not save it as memory.
- Prefer updating an existing memory over creating a new one.
- If unsure whether something should be remembered, do not save it.
