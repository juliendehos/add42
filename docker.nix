# nix-build docker.nix
# docker load < result
# docker run -it --rm -p 3000:3000 add42:latest

{ pkgs ? import <nixpkgs> {} }:

let
  app = pkgs.callPackage ./default.nix {};

  entrypoint = pkgs.writeScript "entrypoint.sh" ''
    #!${pkgs.stdenv.shell}
    $@
  '';

in
  pkgs.dockerTools.buildLayeredImage {
    name = "add42";
    tag = "latest";
    config = {
      WorkingDir = "${app}";
      Entrypoint = [ entrypoint ];
      Cmd = [ "${app}/bin/add42.out" ];
    };
  }


