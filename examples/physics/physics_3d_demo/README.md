# Physics 3D demo

Walk around and drop boxes and spheres.

TODO:
- Use glTF for both level models.
- Use lights designed in CGE editor, not in X3D. Do not use `CastGlobalLights`.
- Load both castle-transform through TSerializedComponent, to make them fast.

Using [Castle Game Engine](https://castle-engine.io/).

## Building

Compile by:

- [CGE editor](https://castle-engine.io/manual_editor.php). Just use menu item _"Compile"_.

- Or use [CGE command-line build tool](https://castle-engine.io/build_tool). Run `castle-engine compile` in this directory.

- Or use [Lazarus](https://www.lazarus-ide.org/). Open in Lazarus `physics_3d_demo_standalone.lpi` file and compile / run from Lazarus. Make sure to first register [CGE Lazarus packages](https://castle-engine.io/documentation.php).
