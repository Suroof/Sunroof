package com.first.sys.controller;

import com.first.common.vo.Result;
import com.first.sys.entity.UserInfo;
import com.first.sys.mapper.UserInfoMapper;
import com.first.sys.service.IUserInfoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.stereotype.Controller;

import java.util.List;
import java.util.Map;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author baomidou
 * @since 2024-09-12
 */
@CrossOrigin
@RestController
@RequestMapping("/userInfo")
public class UserInfoController {

    @Autowired
    private UserInfoMapper userInfoMapper;

    @GetMapping
    public List<UserInfo> getAllUsers() {
        return userInfoMapper.selectAll();
    }

    @GetMapping("/{id}")
    public UserInfo getUserById(@PathVariable Long id) {
        return userInfoMapper.selectById(id);
    }

    @PostMapping("/addUser")
    public void createUser(@RequestBody UserInfo userInfo) {
        userInfoMapper.insert(userInfo);
    }

    @PutMapping("/{id}")
    public void updateUser(@PathVariable Long id, @RequestBody UserInfo userInfo) {
        userInfo.setId(Math.toIntExact(id));
        userInfoMapper.update(userInfo);
    }

    @DeleteMapping("/{id}")
    public void deleteUser(@PathVariable Long id) {
        userInfoMapper.delete(id);
    }
}
//
//    @GetMapping("/{id}")
//    public ResponseEntity<UserInfo> getUserById(@PathVariable Long id) {
//        UserInfo user = userInfoService.getUserById(id);
//        if (user == null) {
//            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
//        }
//        return new ResponseEntity<>(user, HttpStatus.OK);
//    }
//
//    @PostMapping("/")
//    public ResponseEntity<UserInfo> createUser(@RequestBody UserInfo userInfo) {
//        boolean created = userInfoService.createUser(userInfo);
//        if (created) {
//            return new ResponseEntity<>(userInfo, HttpStatus.CREATED);
//        } else {
//            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
//        }
//    }
//
//    @PutMapping("/")
//    public ResponseEntity<UserInfo> updateUser(@RequestBody UserInfo userInfo) {
//        boolean updated = userInfoService.updateUser(userInfo);
//        if (updated) {
//            return new ResponseEntity<>(userInfo, HttpStatus.OK);
//        } else {
//            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
//        }
//    }
//
//    @DeleteMapping("/{id}")
//    public ResponseEntity<Void> deleteUser(@PathVariable Long id) {
//        boolean deleted = userInfoService.deleteUser(id);
//        if (deleted) {
//            return new ResponseEntity<>(HttpStatus.NO_CONTENT);
//        } else {
//            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
//        }
//    }
//
//    @PostMapping("/login")
//    public ResponseEntity<Map<String, Object>> login(@RequestBody UserInfo userInfo) {
//        Map<String, Object> loginResult = userInfoService.login(userInfo);
//        return new ResponseEntity<>(loginResult, HttpStatus.OK);
//    }