
# Setting up your shared home directories on Mac OSX

We are using the machine `goyle.socs.uoguelph.ca` for this course in this
term.  You can access this machine using `ssh(1)` in the same manner that
you access the department Linux environment:

    ssh myname@goyle.socs.uoguelph.ca

Due to the way that Apple negotiates the login process, however, it has
not been possible to get your usual home directories mounted as part of
the login.

This is done easily on Linux as the home directories, which are
physically present on `gringotts.socs` can be mounted after the user identity
is established.

On MacOSX, the system wants the login home directory to exist earlier in
the identity process, creating a chicken-and-egg problem for the mounting
of your shared files.

Because of this, we have provided you a utility to mount the home directory
afterwards.  Simply run

    SoCSMount.sh

and you will be prompted for your central login password (to authenticate
access to your files).  This will then place the directory tree that you
normally see in your `${HOME}` in Linux in a directory on your desktop
named after your user id.

## Checking whether it worked
You should see output telling you whether the mount worked.  For example:

    $ SoCSMount.sh
    ahamil01@CFS.UOGUELPH.CA's password:
    Mounting user workspace directory /Users/ahamil01/Desktop/ahamil01

You must of course see your own userid rather than  `ahamil01`.

In addition, you will see that the directory named after your user id that
has been placed in your Desktop directory has files in it.  In addition,
the mount will be visible in the output from `df(1)`), which reports disk filesystem usage.  The below output is all one line, shown wrapped here.
disk filesystem usage).

    df -H | grep ${USER}
    gringotts:/export/home/faculty/ahamil01  524288000  2528016  521759984     1%   33901           521759984    0%   /Users/ahamil01/Desktop/ahamil01

If you are unable to mount your filesystem on `goyle`, please email `help@socs.uoguelph.ca`.

