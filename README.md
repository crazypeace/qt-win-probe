# Qt 6.11.2 static build probe — windows-latest (Windows Server 2025)

Minimal reproduction project to test whether **Qt 6.11.2 built from source the same way
as Forkgram tdesktop** compiles+installs on GitHub Actions `windows-latest`
(which is `windows-2025`, i.e. Windows Server 2025).

## What it does

Mirrors the Qt stage of tdesktop `Telegram/build/prepare/prepare.py`:

1. `git clone -b v6.11.2 https://github.com/qt/qt5.git`
2. submodules: `qtbase qtimageformats qtshadertools qtsvg`
3. `configure.bat -static -static-runtime -debug-and-release ...`
4. `cmake --build . --config Debug` + `cmake --install . --config Debug`
5. `cmake --build . --config Release` + `cmake --install . --config Release`
6. installs into `%USERPROFILE%\TBuild\Libraries\win64\Qt-6.11.2` (same path layout)

## Deliberate simplifications (isolation)

- No desktop-app qtbase / qt6_windows7 patches
- No external system libs (openssl / libwebp / mozjpeg / zlib / lcms2 / ANGLE) — Qt uses its bundled ones

Goal: isolate whether the failure seen in tdesktop (Qt install `file cannot create directory`)
is caused by the base image / Qt itself, or by tdesktop's patches/config/deps.

## Run

Actions → "Qt 6.11.2 static build probe (windows-latest)" → Run workflow.