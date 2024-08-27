@echo off

REM change working directory to repository directory
cd /D "%~dp0/.."

py -3.12 -m pip wheel . -w dist
py -3.11 -m pip wheel . -w dist
py -3.10 -m pip wheel . -w dist
py -3.9 -m pip wheel . -w dist
py -3.8 -m pip wheel . -w dist
py -3.7 -m pip wheel . -w dist

py -m build . --sdist
