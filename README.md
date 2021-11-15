# 1. Release: high optimization level, no debug info, code or asserts.
# 2. Debug: No optimization, asserts enabled, [custom debug (output) code enabled],
##   debug info included in executable (so you can step through the code with a
##   debugger and have address to source-file:line-number translation).
# 3. RelWithDebInfo: optimized, *with* debug info, but no debug (output) code or asserts.
# 4. MinSizeRel: same as Release but optimizing for size rather than speed.