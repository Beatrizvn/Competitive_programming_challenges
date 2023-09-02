import java.io.*
import java.math.*
import java.security.*
import java.text.*
import java.util.*
import java.util.concurrent.*
import java.util.function.*
import java.util.regex.*
import java.util.stream.*
import kotlin.collections.*
import kotlin.comparisons.*
import kotlin.io.*
import kotlin.jvm.*
import kotlin.jvm.functions.*
import kotlin.jvm.internal.*
import kotlin.ranges.*
import kotlin.sequences.*
import kotlin.text.*

/*
 * Complete the 'aVeryBigSum' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER_ARRAY ar as parameter.
 */

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

fun staircase(n: Int): Unit {

    //5 vazios 1 #
    //4 vazios 2 #
    //3 vazios 3 #
    //2 vazios 4 #
    //1 vazios 5 #
    //0 vazios 6 #

    //vazios = n-i
    //# = i
    for (i in 1..n) {
        var v = (n-i)
        for(j in 1..v){
            print(" ")
        }
        for(k in 1..i){
            print("#")
        }
        println()
    }

}

fun main(args: Array<String>) {
    staircase(6)

}
