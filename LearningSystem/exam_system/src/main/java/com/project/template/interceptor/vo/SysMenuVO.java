package com.project.template.interceptor.vo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class SysMenuVO {

    private String title;

    private String path;

    private String componentPath;

    private String iconClass;

    private Boolean isPage;

    private List<SysMenuVO> list;



}
