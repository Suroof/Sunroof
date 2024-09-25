package com.first;

import com.baomidou.mybatisplus.generator.FastAutoGenerator;
import com.baomidou.mybatisplus.generator.config.OutputFile;
import com.baomidou.mybatisplus.generator.engine.FreemarkerTemplateEngine;

import java.util.Collections;

public class CodeGenerator {
    public static void main(String[] args) {
        String url = "jdbc:mysql:///pro_fi";
        String username = "root";
        String password = "363388";
        String moduleName = "sys";
        String mapperLocation = "D:\\Work\\Vue用户管理系统\\Profi\\src\\main\\resources\\mapper\\" + moduleName;
        String tables = "user_info,goods";
        FastAutoGenerator.create(url, username, password)
            .globalConfig(builder -> {
                builder.author("baomidou") // 设置作者
//                        .enableSwagger() // 开启 swagger 模式
                        .outputDir("D:\\Work\\Vue用户管理系统\\Profi\\src\\main\\java"); // 指定输出目录
            })
            .packageConfig(builder ->
                    builder.parent("com.first") // 设置父包名
                            .moduleName(moduleName) // 设置父包模块名
                            .pathInfo(Collections.singletonMap(OutputFile.xml, mapperLocation)) // 设置mapperXml生成路径
            )
            .strategyConfig(builder ->
                    builder.addInclude(tables) // 设置需要生成的表名
                            .addTablePrefix("t_", "c_") // 设置过滤表前缀
            )
            .templateEngine(new FreemarkerTemplateEngine()) // 使用Freemarker引擎模板，默认的是Velocity引擎模板
            .execute();
    }
}
