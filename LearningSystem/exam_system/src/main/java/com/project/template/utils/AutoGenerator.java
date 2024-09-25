package com.project.template.utils;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.generator.FastAutoGenerator;
import com.baomidou.mybatisplus.generator.config.OutputFile;
import com.baomidou.mybatisplus.generator.config.TemplateType;
import com.baomidou.mybatisplus.generator.config.builder.CustomFile;
import com.project.template.entity.BaseEntity;

import java.nio.file.Paths;
import java.util.*;
public class AutoGenerator {

    private static final String URL = "jdbc:mysql://localhost:3306/exam_system?useSSL=false&useUnicode=true&characterEncoding=utf-8&serverTimezone=GMT%2B8";
    private static final String user = "root";
    private static final String PASSWORD = "root";
    public static void main(String[] args) {
        List<String> tables = new ArrayList<>();
        tables.add("link");
        FastAutoGenerator.create(URL, user, PASSWORD)
                .globalConfig(builder -> {
                    builder.author("Slipknot")               //作者
                            .outputDir(Paths.get(System.getProperty("user.dir")) + "/src/main/java")
                            .enableSwagger()           //开启swagger
//                            .commentDate("yyyy-MM-dd")
                            .disableOpenDir();     //禁止自动打卡目录
                })
                .packageConfig(builder -> {
                    builder.parent("com.project.template")
                            //留空请求路径中就会少一个层级 原层级/blog//user 现层级/user
                            .moduleName("")
                            .entity("entity")
                            .service("service")
                            .serviceImpl("service.impl")
                            .controller("controller")
                            .mapper("mapper")
                            .xml("mapper")
                            .pathInfo(Collections.singletonMap(OutputFile.xml, System.getProperty("user.dir") + "\\src\\main\\resources\\mapper"));
                })
                .strategyConfig(builder -> {
                    builder.addInclude(tables)
//                            .addTablePrefix("p_")
                            .controllerBuilder()
                            .enableRestStyle()
                            .enableFileOverride()
                            .serviceBuilder()
                            .enableFileOverride()
                            .formatServiceFileName("%sService")
                            .formatServiceImplFileName("%sServiceImpl")
                            .entityBuilder()
                            .enableFileOverride()
                            .superClass(BaseEntity.class)
                            //开启Lombok，默认生成@Get，@Set，可以手动换成@Data
//                            .addTableFills(new Column("create_time", FieldFill.INSERT))
//                            .addTableFills(new Column("update_time", FieldFill.UPDATE))
                            .enableLombok()
//                            .logicDeleteColumnName("deleted")
//                            .enableTableFieldAnnotation()
//                            .controllerBuilder()
                            //如果没有父类请注释掉
//                            .superClass(BaseController.class)
//                            .formatFileName("%sController")
//                            .enableRestStyle()

                            .mapperBuilder()
                            .enableFileOverride()
                            .enableBaseResultMap()  //生成通用的resultMap
                            .superClass(BaseMapper.class)
                            .formatMapperFileName("%sMapper")
                            .enableMapperAnnotation()
                            .formatXmlFileName("%sMapper")
                            .enableFileOverride();
                })
                .templateConfig(builder -> {
                    builder.disable(TemplateType.ENTITY)
                            .entity("/templates/entity.java")
                            .service("/templates/service.java")
                            .serviceImpl("/templates/serviceImpl.java")
                            .mapper("/templates/mapper.java")
                            .xml("/templates/mapper.xml")
                            .controller("/templates/controller.java")
                            .build();
                })
                .injectionConfig(consumer -> {
                    List<CustomFile> customFileList = new ArrayList<>();
                    customFileList.add(new CustomFile.Builder().formatNameFunction(tableInfo -> tableInfo.getEntityName()).fileName("Manage.vue").filePath( System.getProperty("user.dir") +"/web/src/views/admin/").templatePath("/templates/page.vue.vm").enableFileOverride().build());
                    consumer.customFile(customFileList);
                }).execute();
    }
}
