# Getting Started
We will be using a number of modern development tools and practices in order to work on our project. 

If you have any issues feel free to contact: 
  - (fixMe)

## Tools:
You will need the following tools to configure the project (we reccommend you follow the [Configuration Steps](#configuration-steps) Below):
  - [GitHub](https://github.com/)
  - [Microsoft VS Code](https://code.visualstudio.com/docs)
  - [GitHub](https://github.com/)
  - [Microsoft VS Code](https://code.visualstudio.com/docs)
  - [A C++ Compiler](https://code.visualstudio.com/docs/languages/cpp)
  - [git](https://git-scm.com/downloads)
  - [CMake](https://cliutils.gitlab.io/modern-cmake/)
  - [Google's C++ Style Guide](https://google.github.io/styleguide/cppguide.html) (This is something used as a refrence for our coding style)

## Configuration Steps
In order to complete these steps, you will need administrator rights on your system.

### Step 1:Getting the IDE
We will be using [Microsoft's VS Code](https://code.visualstudio.com/docs/setup/setup-overview) as our IDE of choice. It is free, heavily extensible, and available on all major platforms. It also has support for any number of programming languages, which makes it a versitle tool for developers. The major drawback with vscode? It trades versatility for a heavy configuration load on the user.

Follow these steps to get vscode:

  1) Go to [Microsoft's VS Code](https://code.visualstudio.com/docs/setup/setup-overview) website.
  2) under the section titled "Cross Platform", click on the link for your os platform (if you have windows, click on windows. for mac, click macOS. etc.)
  3) follow the Installation instructions for the Visual Studio Code Installer option. It is highly recommended to use the default options for the installer.
      1) click on the Visual Studio Code Installer link, it should automatically download the installer application to your default download location.
      2) once it is done installing, your browser should show you where the installer was downloaded. Go to this location (typically a folder named "Downloads") and double click on the vscode installer to run it.
      3) accept the terms and conditions, and click next for each of the install options. We will be using a default install.
      4) vscode should install and open a vscode window.

### Step 2: Configuring vscode
Vscode is highly configureable, which is both a blessing and a curse. On the one hand it can do almost anything you want tell it to do. On the other, you will have to tell it precisely what you want it to do. This can be quite the headache, so follow these steps as best you can.

  1) Vscode should have automatically launched after the installer finished. If not, search for the application and launch it (on windows, press the windows key, type in "vscode", and click on the vscode option when it comes up to launch)
  2) The first time you run Vscode it will welcome you with a "get started" page. The first one is named "choose your theme". this option is personal prefrence, choose the one you think looks nicer. (I prefer Dark Modern)
  3) the next option is called "Rich support for all your languages". go ahead and skip this one for now, we will get back to it
  4) under "tune your settings", clock on "Open Settings". This will open your vscode Settings
      1) in the bar labeled "search settings" type in "tab size" and set the option "tab size" to 2 (refrence Google's [Style Sheet](https://google.github.io/styleguide/cppguide.html#Spaces_vs._Tabs)for why)
      2) in the search bar again, type in "ruler". this should bring up the "Editor:Rulers" option.
      3) under "Editor:Rulers", it should say "Edit in settings.json". click on this link
      4) you should see a .json file named "settings.json" open in the text editor with a option "editor.rulers": []. Within the brackets "[]" type in the number 80. settings.json should look like 
        ``` json
        {
        "editor.rulers": [80]
        }
        ```
      5) save the file by pressing the keybind "ctrl+s" (read as "control s", press the ctrl button and then the s button)
      6) you should see a thin line appear to the right in your text editor. This is the max length we should make any one line.
      7) close the settings.json file in the editor and return to your settings page.
  5) close your settings page and return to the get started page.
  6) If you want to get to know Vscode a bit more, they have some great tutorial videos under the "watch video tutorials" option.
  7) once you're ready to move on, go ahead and click on the "next section" option, and move on to the [Install Git](#step-3-install-git) section.

### Step 3: Install Git
We are now on the "Learn the Fundamentals" page on vscode. You can click around if you want, but for now we are only interested in one option: Install Git. Go ahead and click on this option and the "Install Git" button. This will take you to the [Git website](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) Where we will follow the instructions for installing git.

  1) just like installing vscode, navigate to the install option for your os platform and follow the install directions to get the installer (Download the 64 bit option)
  2) run the installer just like you did for vscode, do not modify the default options and click next until you get to install, then click install. When the install is finished, click finish.
  3) open a command prompt for your machine. This will vary according to your os platform, but on windows you may press win+r and type in cmd.
  4) this is a command terminal, and will be an integral tool for your software development career.
  5) in the terminal, type the command "git --version" to make sure git was installed. if it is installed correctly, it should print out a version which looks something like this: git version 2.33.0.windows.2
  6) DO NOT stress if your version is different from mine. The important thing is that the git command is known to the system, so as long as it prints something you should be good.
  7) if your cmd prompt does not recognize the git command, do not panic. Here are some common trouble shooting steps:
      1) restart your command prompt by closing it out and reopening it. Sometimes your System path may not be updated properly.
      2) restart your computer. Again, sometimes weird things happen and a simple restart could fix it.
      3) attempt to reinstall git. if all else fails, the git installer will know what to do, and given you use the same (default) installation options it should fix your issue.

### Step 4: Setting Up C++ for Vscode
C++ is a programming language, and we need to configure vscode to work with it. We will be following [Microsoft's vscode C++ setup](https://code.visualstudio.com/docs/languages/cpp) instructions.

  1) install the vscode C++ language extension as per [Microsoft's vscode C++ setup](https://code.visualstudio.com/docs/languages/cpp) instructions
  2) while we're at it, install the microsoft C/C++ Extension Pack in the same way. (Note this will also install the CMake tools extension, which we will need later.)
  3) we now need a compiler. We will be using GCC across all platforms for consistency. the following links will tell you how to install on each platform:
  (note: use the defaults! the guides support default installations.)
      - [Windows](https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites) We use Mingw-64 to install a bunch of useful tools
      - [Linux](https://code.visualstudio.com/docs/cpp/config-linux#_prerequisites) We use the built in apt-get package manager
      - [MacOS](https://www.youtube.com/watch?v=0z-fCNNqfEg) We install and use the Mac package manager HomeBrew
  4) The install process is a bit different for each platform, so make sure you refer to the appropriate documentation.
  5) Open a command prompt like we did for git, and type in g++ --version
  6) If the command is recognized and returns a version, go ahead and move on. if not try the following steps:
      1) restart your command prompt by closing it out and reopening it. Sometimes your System path may not be updated properly.
      2) restart your computer. Again, sometimes weird things happen and a simple restart could fix it.
      3) attempt to reinstall GCC using the above 
      4) contact your professor and try to fix it during office hours.

### Step 5: Installing CMake
CMake is an invaluable tool for creating complex projects in C and C++. We will use it to manage our project's lifecycle and simplify our build process. Note that you can link and build projects with just your compiler and linker, Cmake simply standardizes the process and makes building projects much easier. [An Introduction to Modern CMake](https://cliutils.gitlab.io/modern-cmake/) is a great resource if you would like to learn more about modern CMake, and kitware has a [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html) which goes into more detail about their product.

  1) go to the [official Cmake Downloads](https://cmake.org/download/) page and find the x64 installer matching your os Platform
  2) install the cmake Installer, and proceed through the default installation process as above.
  3) open a new command terminal and check to see that it installed correctly by typing in the command cmake --version (do you see a pattern here?)
  4) if it was installed correctly, the command should be recognized and a versoin printed out. if not try the following troubleshooting steps:
      1) restart your command prompt by closing it out and reopening it. Sometimes your System path may not be updated properly.
      2) restart your computer. Again, sometimes weird things happen and a simple restart could fix it.
      3) attempt to reinstall CMake. if all else fails, the git installer will know what to do, and given you use the same (default) installation options it should fix your issue.
  5) next, open your vscode IDE and navigate to the "extensions" card again.
  6) search the extensions marketplace for "cmake". 
  7) this should bring up a list of CMake extensions. Check to see if "CMake" by twxs, and "CMake Tools" by Microsoft are installed by clicking on each.
  8) if these extensions are not installed, make sure that you have installed the "C/C++ Extension Pack" from Microsoft, as this extension automatically includes the Cmake ones.

  ### Step 6: Getting the source (From Github)
  This is where we will finally bring everything together and get a build running.

  1) if you don't have a [Github Account](https://github.com/) yet, well you should! Follow the directions to make an account, and come back here once you're done.
  2) navigate to the [Game Project source](https://github.com/R2steven/cmpsci236Game) on Github, and find the button Labled "Fork" in the top right hand corner of the project.
  3) click on the fork button, and follow the prompts to create your own, personal branch of the project.
  4) the cool thing about forking the repository is that it is now yours to do what you will with. When you are forking repositories, just make sure you read the [License](https://github.com/R2steven/cmpsci236Game/blob/master/LICENSE) to make sure you are following the repository's terms and conditions of use. In our case, we have an MIT Liscence which places very few restrictions on how you can use the code. Repositories with this type of licence are called "Open Source", and often encourage developers of all skill levels to contribute to the project.
  5) once you have your fork on github, it's time to download the source code to your local machine.
  6) open a command prompt on your computer as above and navigate to a convenient home folder. 
      - on Windows, type the command cd C:\ into your console (cd stands for "change directory"!)
      - on Linux and MacOS (Unix Systems), type cd ~
  7) Next, create a development folder to hold your projects
      - on Windows type command: mkdir development
      - on Unix, type command: sudo mkdir development, and enter your computer login credentials when prompted
  8) cd into development with: cd ./development (the "." means "current directory", and "/development" is the path to the folder you want to cd into)
  9) now we will use git to clone your project repository: git clone "https://github.com/YOUR_USER_NAME/cmpsci236Game.git" . (Note: Make suer to replace YOUR_USER_NAME in the url with your github userName)
  10) git will now copy your fork into the development directory
  11) next you will cd into the repository on your machine
      - on Windows, type in the command: cd C:\development\cmpsci236Game
      - on Linux and MacOS (Unix Systems), type the command: cd ~/development/cmpsci236Game
  12) open the repository in vscode with the following command:
      - on Windows: code .
      - on Unix: sudo code .
  13) if vscode asks you to trust the authors, go ahead and click "trust"

### Step 7: Building the Game With CMake
We are now in Vscode and ready to setup our build and project settings.

  1) on the left hand side, below the extension MarketPlace card, we should have a cmake card. go ahead and click on it. (if you dont have it mare sure you have the C++ Extension Pack installed from the extension MarketPlace)
  2) This is the Cmake extension menu for vscode, It contains a gui for doing many common CMake operations, but is hard to describe in a tutorial. we will use the vscode command prompt instead.
  3) hit the keybind crtl+shift+p. this should pull up a text bar.
  4) type in ">CMake:Configure" and select the command which matches
  5) when prompted for our cmake kit, select the option which starts with "GCC", it should look similar to "GCC 13.2.0 x86_64..." (if you cant find it here go back to the troubleshooting steps for our GCC compiler)
  6) You should see a folder named "build" appear in your project folder, and the terminal in vscode should say something like "Build files have been written to: //Path/to/your/project"
  7) Congratulations! you have built your Game Project for the first time. Next we have to do some light housekeeping, and you should be fully ready to start working.

### Step 8: Some light Housekeeping
You may now notice that your source control card in vscode has hundreds of new files added to it. These files were added to your project by CMake when it created its build folder. this folder is necessary to run your game, but we don't want it to clutter up git repository. We will therefore add a .gitignore file to tell git not to track this folder.

  1) in the vscode file explorer card, select the option to "add file" and name it .gitignore
  2) open the .gitignore file and add the following:

```
    # gitignore #
    .gitignore

    # Visual Studio Code # 
    .vscode/

    # cmake build dir #
    build/
```
  3) save and close the .gitignore file, and all those pesky files should no longer be tracked

Lastly we need to tell CMake to pull up a console terminal so we can see the output of our code.

  1) press the hotkey cntl+shift+p to bring up our vscode command prompt
  2) Type in "settings.json" and select the option "Preferences: Open Workspace Settings (JSON). This will open a settings.json for your workspace.
  3) within the brackets, enter the following:
```json
    "cmake.debugConfig": {
        "externalConsole": true,
    }
```
  4) save and close the settings.json file
  5) open the cpp file 236Game/GameApp.cpp in your editor
  6) find the main method, and left click on the just to the left of the line number
  7) you should see a red dot appear next to the line number: this is called a breakpoint.
  6) press ctrl+shift+p and select the CMake: Debug option
  7) select the option labled "Game". this will build attacth a debugger to the game App
  8) you should see that the debugger has stopped on the breakpoint in vscode, and that it has opened a new console.
  9) you can now step though the code and see how the terminal is updated line by line.
