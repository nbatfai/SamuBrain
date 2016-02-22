# SamuBrain

## SamuBrain, exp. 4, cognitive mental organs: MPU (Mental Processing Unit), acquiring higher-order knowledge

Currently I am working on a manuscript titled "Samu in His Prenatal Development" where I want to establish a definition of a mathematical machine for learning. It is for this reason that I have made various experiments on the subject.

The project called SamuBrain is an implementation of a version of the definition in question. In this experiment, I have been investigating the possibility of developing a "cognitive mental organ" which is called Mental Processing Unit (or briefly MPU) in the terminology of the sources of this project.

An MPU consisting of two lattices, one input and one output lattice. The input lattice (called reality) represents the perception of the agent. Each cell of the output lattice (called Samu's predictions) is equipped with 
a [COP](http://arxiv.org/abs/1108.2865)-based
[SAMU](http://arxiv.org/abs/1511.02889)  engine to predict the next state of the corresponding input cell. Three different inputs are shown to the agent in the experiment:

1. 5 gliders move in the input lattice in accordance with Conway's Game of Life (https://github.com/nbatfai/SamuLife)
2. 9 simple "pictures" are shown (https://github.com/nbatfai/SamuStroop)
3. a simple "film" is shown (https://github.com/nbatfai/SamuMovie)

The agent must learn and recognize these complex patterns. It is shown in video at https://youtu.be/_W0Ep2HpJSQ

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



## Experiments with this project

### v.0.0.1 Q-- learning

It is important to note that this COP-based Q-learning (taggeb by "Q---learning") has become trivial because after a short starting period it chooses the Q-action that was passed in as the actual cell state argument. It means that the agent does not predict the future but the present.


```
git clone https://github.com/nbatfai/SamuBrain.git
cd SamuBrain/
git checkout Q---learning
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


![screenshot from 2016-01-30 21-50-44](https://cloud.githubusercontent.com/assets/3148120/12698416/fe0e6020-c79b-11e5-897c-1bb74afba1c3.png)

[https://youtu.be/_W0Ep2HpJSQ](https://youtu.be/_W0Ep2HpJSQ)

### v0.0.2-predicting-the-present-eliminated

This is the improved version of the previous one.

[https://youtu.be/FkyxxCfQeiY](https://youtu.be/FkyxxCfQeiY)


### The branch 'analytics'

![screenshot from 2016-02-08 19-57-05](https://cloud.githubusercontent.com/assets/3148120/12895739/33a73c26-ce9e-11e5-9131-ab03cd090877.png)

[https://youtu.be/NXKdjKCSFG4](https://youtu.be/NXKdjKCSFG4)

## Previous other experiments

Samu (Nahshon)
http://arxiv.org/abs/1511.02889,
https://github.com/nbatfai/nahshon

---

SamuLife
https://github.com/nbatfai/SamuLife,
https://youtu.be/b60m__3I-UM

SamuMovie
https://github.com/nbatfai/SamuMovie,
https://youtu.be/XOPORbI1hz4

SamuStroop
https://github.com/nbatfai/SamuStroop,
https://youtu.be/6elIla_bIrw,
https://youtu.be/VujHHeYuzIk

SamuCopy
https://github.com/nbatfai/SamuCopy

---

SamuTicker
https://github.com/nbatfai/SamuTicker

SamuVocab
https://github.com/nbatfai/SamuVocab
