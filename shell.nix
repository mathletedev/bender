{ pkgs ? import <nixpkgs> { } }:

with pkgs; mkShell rec {
  buildInputs = [
    sfml
  ];

  CMAKE_PREFIX_PATH = "${sfml}";
}
