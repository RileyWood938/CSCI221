Making and running code:

make will run make test_all, creaing an executable that tests each code file

Make %_test where % is some code file name will make a test executable for that code file. IE make powers_test will create the powers_test executable.

 2. (15 points) Shell.
 (a) (3 points) What ags are being passed to the following command? What are the arguments associated with each ag?
 command--abc def-gh ij
The args are --abc and --gh with arguments def and ij respectively.

 (b) (4 points) Assume that you just installed (or wrote) a new library, and you would like to be able
 to run an executable from that library using your shell with one command that did not depend on
 your current working directory. How would you accomplish this?

you can cd into it via a subshell using parentheses like so: (cd /path/ && ./your_executable -ARGS)

 (c) (4 points) Shells have many configurable settings that allow users to modify how they interact with
 the shell. For bash, these settings are stored in the .bashrc file in your home directory. Other
 shells will usually have a similar file. Find and open this file. What are some settings that are
 important to how you interact with the shell? Customize your shell to be useful to you. Submit
 your modified settings file.

Open the file with nano ~/.bashrc. There are some pretty neat settings here. Aliasing commands seems particulatly potent. I stuck with changing color coding properties.

 (d) (4 points) How can you count the number of instances of the word "that" in the first 50 lines of
 the file Logistics.tex using a single command? (The file Logistics.tex is the tex file from the
 very first assignment. Its on Moodle if you want to test your code.)

grep -ciw "this" Logistics.tex

 3. (18 points) Version Control.
 (a) (2 points) What is the difference between creating a repository and cloning a repository?

Creating a repositry makes a new empty repository in the specified location. Cloning a repository creates a copy of an existing repository in the specified location

 (b) (2 points) What is the difference between a staged file and a committed file?

A staged file is flagged on your machine as changed, but has not been updated in the repository whereas a comitted file is a part of your git edit history. 

 (c) (2 points) If you realized that a previous implementation in your project was better for what you
 were trying to do now, and you wanted to return the entire repository to the state at that time,
 what command should you run to do this?

Use git reset, although creating a new branch based off of the past version is better practice so you do not lose any changes.

 (d) (2 points) If you made a mistake while working on a project and wanted to undo the changes you
 made to a particular file, what command should you run to do this

 You generally use git restore or git checkout to get the older version then add it to your current staging. 

 (e) (4 points) Assume that you are working on a project using multiple different machines which each have a copy of the project. If you make changes on one machine, then make changes on another machine prior to synchronizing your repository, you will have to merge your changes. Explain the process of merging changes, including what happens if your different versions changed the same file.

git merge allows you to combine branches. When the same file has been modified there will be conflicts that must be manually dealt with. Git status tells you which files need to be resolved and you must manually edit them to resolve the commit, generally by sticking with the code from one branch or the other.

 (f) (3 points) What is a pull request?

A pull request is a proposal to merge two branches.

 (g) (3 points) What Git command should you use to compare two different commits in the same repository? How does it work?

 git diff shows the differences between files. It compares the files and picks out the differences