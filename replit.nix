{ pkgs }: {
	deps = [
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
		pkgs.sfml
		pkgs.xorg.libX11
		pkgs.gtk3-x11
		pkgs.libbsd
	];
}