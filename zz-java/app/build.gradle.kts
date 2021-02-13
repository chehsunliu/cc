plugins {
    application
    id("com.github.sherter.google-java-format") version "0.8"
}

repositories {
    jcenter()
}

dependencies {
    testImplementation("org.junit.jupiter:junit-jupiter-api:5.6.2")
    testRuntimeOnly("org.junit.jupiter:junit-jupiter-engine:5.6.2")
}

application {
    mainClass.set("com.github.chehsunliu.cc.zz.App")
}

tasks.test {
    useJUnitPlatform()
}
