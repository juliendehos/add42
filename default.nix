{ pkgs ? import <nixpkgs>{} }:

let

  app = pkgs.stdenv.mkDerivation {
    name = "add42";
    src = ./.;
    buildInputs = with pkgs; [
      catch2_3
      cmake

      # git

      (libhv.overrideDerivation (attrs: { cmakeFlags = []; }))

      # libhv
      # (openssl.override { withCryptodev = true; enableSSL2 = true; enableSSL3 = true; }) curl libnghttp2

      mdbook
    ];
    doCheck = true;
  };

  entrypoint = pkgs.writeScript "entrypoint.sh" ''
    #!${pkgs.stdenv.shell}
    $@
  '';

in {

  add42 = app;

  docker-image = pkgs.dockerTools.buildLayeredImage {
    name = "add42";
    tag = "latest";
    config = {
      WorkingDir = "${app}";
      Entrypoint = [ entrypoint ];
      Cmd = [ "${app}/bin/add42.out" ];
    };
  };
  # nix-build -A docker-image
  # docker load < result
  # docker run -it --rm -p 3000:3000 add42:latest

}

