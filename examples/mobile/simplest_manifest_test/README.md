# Simplest Manifest Test

This demo shows that `CastleEngineManifest.xml` file can be very very simple,
you only really need to specify `game_units` to have something working on all platforms.

You *do not need* to specify `standalone_source`, and you *do not need* to keep files generated
by `castle-engine generate-program` in the version control:

- `castleautogenerated.pas`
- `xxx_standalone.dproj`
- `xxx_standalone.lpi`
- `xxx_standalone.dpr`

The build tool will automatically create and use a temporary (in `castle-engine-output/`)
source code for the program/library and `castleautogenerated.pas` unit if they are missing.

The advantage: your directory is cleaner, no need to see/commit auto-generated stuff.

The disadvantage: your project can be build only by CGE editor or CGE build tool
(`castle-engine compile`) out-of-the-box.
You cannot open project with Lazarus or Delphi IDEs out-of-the-box.
