#!/bin/sh
valid_dir=$HOME/Music
invalid_dir=$HOME/Moose

# cd $invalid_dir || cd $valid_dir && ls -al
<<'NOTE:0'
Here we can see the both stderr message and list of files inside music folder
NOTE:0

# cd $invalid_dir || { echo "Error: Path doesn't valid"; exit 1; }
<<'NOTE:1'
Here we can see the messages like ...
    ./Redirect-Message.sh: line 5: cd: /home/arka/Moose: No such file or directory
    Error: Path doesn't valid
So we can see both error messages set by shell and by me.
NOTE:1


# cd $invalid_dir 2>/dev/null || { echo "Error: Path doesn't valid"; exit 1; }
<<'NOTE:2'
Here we get the only error message set by me, since we redirect the error message 
in /dev/null. '2>' is the redirection operator for file descriptor 2, which is typically
the stderr stream.
NOTE:2


cd $invalid_dir > /dev/null 2>&1
cd $valid_dir && ls -al > /dev/null 2>&1
cd $invalid_dir &> /dev/null
cd $valid_dir && ls -al &> /dev/null
<<'NOTE:3'
Here we can't get any output. Since "/dev/null 2>&1" or "&>/dev/null" redirects both 
stdout and stderr to /dev/null.
And we know that we can redirect standad output with > /dev/null
NOTE:3
cd $valid_dir && ls -al > /dev/null

