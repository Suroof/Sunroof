package com.project.template.controller;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.project.template.common.PageVO;
import com.project.template.common.Result;
import com.project.template.entity.ExamQuestion;
import com.project.template.service.ExamQuestionService;
import com.project.template.utils.UserThreadLocal;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * 功能：
 * 作者：程序员瑞哥
 */
@RestController
@RequestMapping("/examQuestion")
public class ExamQuestionController {

    @Resource
    private ExamQuestionService examQuestionService;

    @ApiOperation(value = "列表",notes = "列表")
    @GetMapping("/list")
    private Result<List<ExamQuestion>> list(){
        return new Result().success(examQuestionService.list());
    }
    @GetMapping("/getQuestion")
    public Result getQuestion(@RequestParam("ids") Integer[] ids){
        List<ExamQuestion> list = new ArrayList<>();
        for(Integer id : ids){
            ExamQuestion byId = examQuestionService.getById(id);
            list.add(byId);
        }
        return new Result<>().success(list);
    }
    @GetMapping("/page")
    public Result<PageVO<ExamQuestion>> findPage(
            @RequestParam Map<String,Object> query,
            @RequestParam(defaultValue = "1") Integer pageNum,
            @RequestParam(defaultValue = "10") Integer pageSize
    ){
        Page<ExamQuestion> page= examQuestionService.page(query,pageNum,pageSize);
        return new Result().success(new PageVO<>(page));
    }

    @PostMapping("/add")
//    @Validated
    public Result add(@RequestBody ExamQuestion examQuestion){
        examQuestion.setUserId(UserThreadLocal.getCurrentUser().getId());
        examQuestionService.save(examQuestion);
        return new Result<>().success();
    }

    @PutMapping("/update")
//    @Validated
    public Result updateById(@RequestBody ExamQuestion examQuestion){
        examQuestionService.updateById(examQuestion);
        return new Result<>().success();
    }

    @DeleteMapping("/delBatch")
    public Result delBatch(@RequestBody List<Integer> ids){
        examQuestionService.removeByIds(ids);
        return new Result().success();
    }

}