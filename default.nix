{ pkgs ? import <nixpkgs>{} }:

pkgs.stdenv.mkDerivation {
  name = "add42";
  src = ./.;

  buildInputs = with pkgs; [
    catch2_3
    cmake
    drogon
    mdbook
  ];

  doCheck = true;

}

