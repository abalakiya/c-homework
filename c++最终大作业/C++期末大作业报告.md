## C++期末大作业报告

姓名：郑鑫
学号:18062037

#### 简述

此次作业的主要内容是对github上的开源代码nebula进行单元测试，并用git提交到github上，以此来锻炼我们的代码阅读水平以及项目工程级代码规范以及操作要求。

## 过程描述

#### git的安装

git的安装非常简单，只需要一行命令即可安装

```
sudo apt install git 
```

输入完成之后再输入自己的电脑密码即可开始安装

#### git 环境配置

用git创建远程连接需要在github里创建秘匙

##### 第一步

```
ssh-keygen -t rsa -C "940824241@qq.com"
```

使用ssh创建秘匙

##### 第二步

```
cd  ~/.ssh
```

进入.ssh目录下

##### 第三步

```
more id_rsa.pub
```

在id_rsa.pub文件中找到秘匙 ![1](C:\Users\lenovo\Desktop\c++\1.png)

##### 第四步

将所有秘匙复制，并进入github，在左上角进入Settings-->SSH and GPG keys --> new ssh key ![2](C:\Users\lenovo\Desktop\c++\2.jpg)

将秘匙粘贴到Key中并保存 

完成后会显示如下界面 最后，在终端输入

```
ssh -T git@github.com
```

 这是远程访问github命令，若显示如图，则git成功连接github

![4](C:\Users\lenovo\Desktop\c++\4.jpg)

#### nebula安装与启动

安装完git后就能用git从github上克隆代码到本地了

##### 第一步

进入nebula创建者的主页，fork到自己的主页下

```
git clone https://github.com/940824241/nebula.git
```

将代码拷贝到本地

##### 第二步

```
cd nebula
```

进入nebula文件夹

```
 ./build_dep.sh
```

安装依赖

```
source ~/.bashrc
mkdir build
```

创建build文件夹

```
cd build
```

进入build文件夹

```
cmake ..

make
```

![6](C:\Users\lenovo\Desktop\c++\6.jpg)

等待一段时间直到完成

```
sudo make install
```



安装make下来的文件![7](C:\Users\lenovo\Desktop\c++\7.jpg)

```
cd /usr/local/nebula/etc

sudo cp etc/nebula-graphd.conf.default etc/nebula-graphd.conf
sudocp etc/nebula-metad.conf.default etc/nebula-metad.conf
sudo cp etc/nebula-storaged.conf.default etc/nebula-storaged.conf
```

这就配置完成了nebula

##### 启动nebula

```
bash> ./scripts/nebula.service start all
bash> ./bin/nebula -u user -p password --port 3699 --addr "127.0.0.1"
```

这两行命令用于启动nebula  ![11](C:\Users\lenovo\Desktop\c++\11.jpg)

(当时拍摄比较随意角度比较斜)

但视频中成功后运行上述代码应是

![10](C:\Users\lenovo\Desktop\c++\10.png)

所以不知道我这边有没有成功，问题在哪

###### 但确实可以打开一些文件

![9](C:\Users\lenovo\Desktop\c++\9.jpg)

#### 实验心得

心得： 经过本次实验，我更加了解了git的使用，同时对个github的了解也提升了一个层面，我懂得了如何用git提交代码，以及如何用github的commit与源代码作者进行交流，此外，我对大项目的理解程度更上一层，我还懂得了如何月嗯cmake编译代码以及如何直接调用make完的代码。

遇到的困难有： 第一次fork下来的代码是老版本的代码，无法进行编译，之后通过老师的帮助得到了新的代码。

##### git提交代码到github

在之前的草错中我们已经从github fork了别人的代码。这样我们已经和我们fork下来的仓库建立了远程联系。

```
cd nebula
```

之后我们就可以进入到nebula文件夹中

```
git add .
```

将改动的部分添加到git暂存区域中

```
git commit -m "nebula"
```

将我们这次改动标记为nebula并且将暂存区里的改动给提交到本地的版本库

```
git push
```

这样子就能直接将代码改动提交到github上了

但是我在最后想要push时总是出现错误

我猜想是本地电脑与远程的github连接不稳定，导致之前成功连接，过了几个小时之后就断了

当输入 

```
ssh -T git@github.com
```

总是报出Permission denied (publickey)的错误

![3](C:\Users\lenovo\Desktop\c++\3.jpg)

按照技术文档中说的在命令行中

```
eval "$(ssh-agent -s)"

ssh-add
```

之后还是一样。唉。。。

#### 未能成功pull requests的原因

对git的使用不熟练，其实大一的暑假的时候我参加社团的学长已经要求我们去学习使用github了，但是我实在是太懒惰贪玩了，所以直到现在都不是很熟练，遇到各种问题还需要一直请教同学老师自己无法解决，唉。。。

时间实在太少了，前几周一直把这件事托着，一直没去做，到了期末有各种各样的大作业需要交，做这个c++大作业的时间没剩下多少，还得留出时间复习准备考试，唉。班里有很多同学会的比我多，也比我努力，对这门课的学习让我充分的认识到自己和别的同学之间的差距，大家已经把大作业做的很完美了，而我还什么都不会。。。

# request

希望老师给俺们班的分数能高一点点，因为别的班级选的c++课老师教授的内容有点基础简单，所以这门课他们的分数会比较高，您的课上教授的东西肯定是更加多的，所以大家可能看上去有点跟不上，但绝对不是我们不行！！！