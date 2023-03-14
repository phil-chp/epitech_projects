[< Back](../../README.md)

Doing a simple nmap of the ip given is a real headache, almost all 65k ports are opened to random interfaces, machines, routers, etc

Let's start with the given description to the CTF: port 109

```
❯ nc [IP] 109
I am lost, can you find me ? I'm usually on the top 100 ports
```

I made a python script to iterate over all ports and print their content in a markdown formatted output ([Port_Info](./Port_Info.md))

After taking a close look at ports 1-100, it seems that ports 51-64 have something in common, and they're unicode characters, let's print those again but in unicode:

```
550 12345 ⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
550 12345 ⠄⠄⠄⠄⠄⠄⠄⠄⠄⣀⣤⣴⣶⣶⣶⣶⣶⣶⣤⣄⣀⠄⠄⠄⠄⠄⠄⠄g⠄
550 12345 ⠄⠄⠄⠄⠄⢀⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⠄⠄⠄⠄o⠄
550 12345 ⠄⠄⠄⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣆⠄⠄⠄⠄
550 12345 ⠄⠄⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠄p⠄
550 12345 ⠄⠄⣾⣿⡿⠟⡋⠉⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠉⠉⠙⠻⣿⣿⣇o⠄
550 12345 ⠄⢠⣿⡏⢰⣿⣿⡇⠄⠄⢸⣿⣿⣿⠿⠿⣿⣿⣿⠁⣾⣿⣷⠄⠄⠘⣿⣿r⠄
550 12345 ⠄⠸⣿⣇⠈⠉⠉⠄⠄⢀⣼⡿⠋⠄⠄⠄⠄⠙⢿⣄⠙⠛⠁⠄⠄⢠⣿⣿t⠄
550 12345 ⠄⠄⢿⣿⡇⠄⠄⠄⣶⣿⣿⢁⣤⣤⣤⣤⣤⣤⠄⣿⣷⠄⠄⠄⠈⢹⣿⡟⠄⠄
550 12345 ⠄⠄⠈⢿⡗⠄⠄⢸⣿⣿⣿⣶⣶⣶⣶⣶⣶⣶⣶⣿⣿⠄⠄⠄⠄⢸⡟⠄2⠄
550 12345 ⠄⠄⠄⠄⠳⡀⠄⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⠄⠄⠄⠌⠄⠄3⠄
550 12345 ⠄⠄⠄⠄⠄⠄⠄⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣤⠄⠄⠄⠄⠄⠄4⠄
550 12345 ⠄⠄⠄⠄⠄⠄⠄⠄⠉⠙⠻⠿⠿⣿⣿⣿⣿⠿⠿⠛⠉⠄⠄⠄⠄⠄⠄⠄5⠄
550 12345 ⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄6⠄
```

Let's take a look at port `23456`:
```
❯ nc [IP] 23456
It remember ! I put the flags in my chest, it's on a nfs share, how do i list them ?
```

Let's take a look at the exposed share points:
```
❯ showmount -e [IP]
Exports list on [IP]:
/home/nfs                           *
```

Let's mount the share point, (I had to add some flags due to MacOS securities):
```
sudo mount -o nolocks,resvport -t nfs [IP]:/home/nfs /tmp
```

Inside the nfs share folder, we find a `chest.zip` file, trying to unzip it requires the user password.

Let's try to crack the zip password using john the ripper (and zip2john):
```
❯ zip2john chest.zip > chest.hash

❯ john chest.hash --wordlist=[PATH]/SecLists/Passwords/Leaked-Databases/rockyou.txt

isaaciscrazy     (chest.zip)
1g 0:00:00:00 DONE (2022-11-25 15:26) 1.162g/s 8486Kp/s 8486Kc/s 8486KC/s isabel123456789..isa_ruben
```

After unlocking the zip file, we find a `flag.txt` file containing the flag:

```
❯ tree -a
.
└── isaac
    ├── .DS_Store
    └── .ssh
        ├── authorized_keys
        ├── flag.txt            <-------- flag
        ├── hint.txt
        ├── id_rsa
        └── id_rsa.pub
```
