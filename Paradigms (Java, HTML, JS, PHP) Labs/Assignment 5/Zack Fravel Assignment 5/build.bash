#1/bin/bash
set -u -e

javac GasTank.java
javac Engine.java
javac Car.java
javac CopCar.java
javac RobberCar.java
javac Sprite.java
javac SpriteMover.java
javac View.java
javac Model.java
javac Controller.java

java Controller