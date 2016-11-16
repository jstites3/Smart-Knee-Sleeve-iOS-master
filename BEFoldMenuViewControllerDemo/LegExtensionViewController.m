//
//  LegExtensionViewController.m
//  BEFoldMenuViewControllerDemo
//
//  Created by Jacques Stites on 11/12/16.
//  Copyright © 2016 Vũ Trường Giang. All rights reserved.
//

#import "LegExtensionViewController.h"

@interface LegExtensionViewController ()

@end

@implementation LegExtensionViewController
{
    NSArray *graphData;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    graphData = [NSArray arrayWithObjects:@1,@2,@3,@4,nil];
    
    BEMSimpleLineGraphView *myGraph = [[BEMSimpleLineGraphView alloc] initWithFrame:CGRectMake(50, 200, 300, 400)];
    myGraph.dataSource = self;
    myGraph.delegate = self;
    [self.view addSubview:myGraph];
    //myGraph.animationGraphStyle = BEMLineAnimationFade;
    
    [myGraph reloadGraph];
    
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (NSInteger)numberOfPointsInLineGraph:(BEMSimpleLineGraphView *)graph {
    return [graphData count]; // Number of points in the graph.
}

- (CGFloat)lineGraph:(BEMSimpleLineGraphView *)graph valueForPointAtIndex:(NSInteger)index {
    return 100; // The value of the point on the Y-Axis for the index.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
