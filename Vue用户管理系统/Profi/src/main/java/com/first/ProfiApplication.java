package com.first;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
@MapperScan("com.first.*.mapper")
public class ProfiApplication {
    public static void main(String[] args) {
        SpringApplication.run(ProfiApplication.class, args);
    }

}
