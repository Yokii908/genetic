# Basic Genetic Algorithm

> Not freeing 100% of the resources.

### Description
This project is a basic genetic algorithm that guesses a string passed as argument.

### Installation

`make`

### Usage
`Usage: ./genetic target population_size mutation_rate`

### Overall method
The goal is to guess the `target`parameter based on potential association with a lot of data.

A `Population` object is instanced. It contains an array of `Entity` objects sized after the `population_size` parameter. `Entity` objects contain a `_dna` string typed. 

A potential value is given to each `Entity` object. This potential value is calculated based on the match with the target. (+1 potential for a correct and well placed character). The potential is squared to make the potential somewhat exponential.

All those `Entity` are placed in a matching pool based on their potential. For example an `Entity` object with a potential of 12 will be placed twelve times in the matching pool which leads it to have more chance to be picked as a parent in the next function.

The `Crossover` function randomly picks two parents in the matching pool. It randomly determines a half point and take the first part of the first parent till the half point and the second part of the second parents after the half point.
For example :

Parent | Dna
------:|:-------
First parent | abcdef
Second parent |	ghijkl
Random cut point |	 4
Child parent		|	abcdkl

Once the child is born it has a chance to mutate based on the `mutation_rate` parameter. The mutation is applied to all chromosomes of its Dna. Basically each characters has a chance to be randomly replaced. It helps creating variety in the population. (the mutation rate is usually about 1%. Too much variety introduced in a new generation is not efficient).

When enough children are born a new population is generated and the whole process is recursively called until a potential equivalent to 100% is found.
