# SamuBrain

## SamuBrain, exp. 4, cognitive mental organs: MPU (Mental Processing Unit), Q-- lerning, acquiring higher-order knowledge

Currently I am working on a manuscript titled "Samu in His Prenatal Development" where I want to establish a definition of a mathematical machine for learning. It is for this reason that I have made various experiments on the subject.

The project called SamuBrain is an implementation of a version of the definition in question. In this experiment, I have been investigating the possibility of developing a "cognitive mental organ" which is called Mental Processing Unit (or briefly MPU) in the terminology of the sources of the project: https://github.com/nbatfai/SamuBrain

An MPU consisting of two lattices, one input and one output lattice. The input lattice (called reality) represents the perception of the agent. Each cell of the output lattice (called Samu's predictions) is equipped with a COP-based[*] SAMU engine[+] to predict the next state of the corresponding input cell. Three different inputs are shown to the agent in the experiment:

-1) 5 gliders move in the input lattice in accordance with Conway's Game of Life (https://github.com/nbatfai/SamuLife)
-2) 9 simple "pictures" are shown (https://github.com/nbatfai/SamuStroop)
-3) a simple "film" is shown (https://github.com/nbatfai/SamuMovie)

The agent must learn and recognize these complex patterns. It is shown in video at https://youtu.be/_W0Ep2HpJSQ

[*]: http://arxiv.org/abs/1108.2865
[+]: http://arxiv.org/abs/1511.02889

## Usage

```
git clone https://github.com/nbatfai/SamuBrain.git
cd SamuBrain/
~/Qt/5.5/gcc_64/bin/qmake SamuLife.pro
make
./SamuBrain 2>out
```

```
tail -f out|grep "HIGHER-ORDER NOTION MONITOR"
```

```
tail -f out|grep SENSITIZATION
```

```
tail -f out|grep "HABITUATION MONITOR" 
```

[https://youtu.be/_W0Ep2HpJSQ](https://youtu.be/_W0Ep2HpJSQ)

## Previous experiments

Samu (Nahshon)
http://arxiv.org/abs/1511.02889
https://github.com/nbatfai/nahshon

SamuLife
https://github.com/nbatfai/SamuLife
https://youtu.be/b60m__3I-UM

SamuMovie
https://github.com/nbatfai/SamuMovie
https://youtu.be/XOPORbI1hz4

SamuStroop
https://github.com/nbatfai/SamuStroop
https://youtu.be/6elIla_bIrw
https://youtu.be/VujHHeYuzIk