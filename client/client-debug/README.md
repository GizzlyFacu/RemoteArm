# Basic Template with CCache

---



Basic startup for a CPP 17 project \*\*without Conan\*\*, this example uses CCache but doesn't matter if you didn't install it yet. It works anyway.



\## Requirements:

* MinGW (gcc / g++) \[Download link + steps](https://www.msys2.org/)

 	- Check the steps in the same download msys2 page.

 	- Add C:\\msys64\\mingw64\\bin to the \[System PATH](https://youtu.be/pGRw1bgb1gU?si=HhE\_k-wTZso74HdD).

 	- Verify: Open Windows Powershell and paste inside "g++ --version", if something happens, it's correctly installed.

 	- \*\*IMPORTANT:\*\* you can use MVSC with Meson if u have already installed Visual Studio. But I use MinGW for better portability.

* Meson: \[Get Meson](https://mesonbuild.com/Getting-meson.html#installing-meson-and-ninja-with-the-msi-installer)

 	- You will need \[Python](https://www.python.org/downloads/)

* Not Required but Useful: CCache

&nbsp;	- Download from \[ccache.dev/download.html](https://ccache.dev/download.html)

&nbsp;	- Add the "bin" folder (where ccache.exe exists) to the \[System PATH](https://youtu.be/pGRw1bgb1gU?si=HhE\_k-wTZso74HdD).

&nbsp;	- Verify: Open Windows Powershell and paste inside "ccache --version", if something happens, it's correctly installed.



\## How to Use:

* click "setup.bat"
* buy 1 kg of Mercury powder.



\## Details:

* Edit the meson.build if you want different names (app.exe, subfolders, etc.) \[Meson Tutorial](https://mesonbuild.com/Tutorial.html)
