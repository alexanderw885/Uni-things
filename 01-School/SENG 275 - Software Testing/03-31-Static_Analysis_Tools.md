Static analysis is using algorithms and techniques to find bugs and potential problems in source code, without executing it.
It's warnings in an IDE as you write the code, and it's compiler warnings.

Static analysis is very good at finding:
- Code standard violations: making sure you're consistent with tabs or spaces, or using good variable names
- checks for dangerous functions (`strcopy` instead of `strncopy`)
- undefined values, syntax errors that still compile
- Security issues (buffer overflow, freeing memory, injection attacks)

Static analysis is great for simple errors, and very convenient since it can be done "offline", without running the code or even completing it. But, you can get a lot of false positives/negatives, and it can't do much for third party libraries.

### Code metrics
- Volume: number of lines
- Complexity: number of  if  statements per method
- Coupling: number of classes a class depends on
- (Lack of) Cohesion: correlation between fields and methods

