cmd_drivers/clocksource/built-in.o :=  aarch64-linux-android-ld -EL   -r -o drivers/clocksource/built-in.o drivers/clocksource/clksrc-of.o drivers/clocksource/cpuxgpt_mt6797.o drivers/clocksource/gpt_mt6797.o drivers/clocksource/arch_timer_mt6797.o drivers/clocksource/dummy_timer.o 
