package distros

import (
	"fmt"
)

func GentooFetch() {
	username, err := GetUserName()
	hostname, err := GetHostName()
	osname,   err := GetOperatingSystemName()
	kernel,   err := GetKernel()
	shell := GetShell()
	de_wm := GetDesktopEnvironment()
	init  := GetInit()
	if err != nil {
		fmt.Println("Ошибащка: ", err)
		return
	}

	fmt.Println(MAGENTA_COLOR, " ", RESET_COLOR)
	fmt.Println(MAGENTA_COLOR, "   _-----_      ", RESET_COLOR, MAGENTA_COLOR,   " User:", username,    RESET_COLOR)
	fmt.Println(MAGENTA_COLOR, "  (       \\    ", RESET_COLOR, MAGENTA_COLOR, "───────────────────",  RESET_COLOR)
	fmt.Println(MAGENTA_COLOR, "  \\    0   \\    ", RESET_COLOR, MAGENTA_COLOR,   "󰌢 Host:",   RESET_COLOR, hostname,  RESET_COLOR)
	fmt.Println(MAGENTA_COLOR, "   \\        )   ", RESET_COLOR, MAGENTA_COLOR,   " OS:",     RESET_COLOR, osname,    RESET_COLOR)
	fmt.Println(MAGENTA_COLOR, "   /       _/   ", RESET_COLOR, MAGENTA_COLOR,   " Kernel:", RESET_COLOR, kernel,    RESET_COLOR)
	fmt.Println(MAGENTA_COLOR, "  (      _-     ", RESET_COLOR, MAGENTA_COLOR,   " Shell:",  RESET_COLOR, shell,     RESET_COLOR)
	fmt.Println(MAGENTA_COLOR, "  \\____-        ", RESET_COLOR, MAGENTA_COLOR,   " DE/WM:",  RESET_COLOR, de_wm,     RESET_COLOR)
	fmt.Println(MAGENTA_COLOR, "                ", RESET_COLOR, MAGENTA_COLOR,   " Init system:", RESET_COLOR, init, RESET_COLOR)
	fmt.Println(MAGENTA_COLOR, "     GENTOO     ", RESET_COLOR, MAGENTA_COLOR,   "", RESET_COLOR)
	fmt.Println(MAGENTA_COLOR, "                ", RESET_COLOR, RED_COLOR,  "█", GREEN_COLOR,
			"█", YELLOW_COLOR, "█", BLUE_COLOR, "█", MAGENTA_COLOR, "█", CYAN_COLOR, "█", RESET_COLOR)
	fmt.Println("")
}
