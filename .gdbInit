# Display Registers on every stop
set print pretty on
define hook-stop
    info registers
end

# Display Assembly Code on every stop
define hook-stop
    x/10i $pc
end

# Set Auto Print
set print pretty on

# Customize the GDB Prompt
set prompt \033[1;31m(gdb)\033[0m

