{
    description = "Dev env for Clang";

    inputs = {
        nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    };

    outputs = { self, nixpkgs, ... }:
        let
            system = "x86_64-linux";
            pkgs = import nixpkgs {
                inherit system;
            };
        in {
            devShells.${system}.default = pkgs.mkShell {
                buildInputs = with pkgs; [
                    clang
                    pkg-config
                    stdenv.cc.cc
                ];

                # After building dltsh try "make run" for run dltsh
                shellHook = ''
                    cd ~/dfetch && make
                    make run
                    exit
                '';
            };
        };
}
