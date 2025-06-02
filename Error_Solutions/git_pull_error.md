### 问题
git pull时无法获取仓库

### 解决方案

`sudo vim /etc/hosts`

将https://dnschecker.org/#A/github.com 中的dns地址填入hosts文件


### 防止wsl自动覆盖hosts

sudo vim /etc/wsl.conf

增加下面两行：

[network]
generateHosts = false

